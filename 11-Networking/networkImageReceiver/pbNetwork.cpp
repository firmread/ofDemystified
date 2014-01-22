#include "pbNetwork.h"

//----------------------------------------------------------------------
//Implementation of some simple protocol

const string PacketMarker = "[Data packet]";
const int PacketMarkerSize = 13;
const int PacketHeaderSize = PacketMarkerSize + 3 * 4;	//frame, size, src32

struct PacketHeader {
	bool valid;
	int frame, size, src32;

	char buffer[ PacketHeaderSize ];
	int bufferSize;
	void setup( int frame0, int size0, int src320, bool fillBuffer )
	{
		valid = true;
		frame = frame0;
		size = size0;
		src32 = src320;
		if ( fillBuffer ) {
			//Filling buffer
			int k=0;
			memcpy( buffer + k, &PacketMarker[0], PacketMarkerSize );
			k += PacketMarkerSize;
			memcpy( buffer + k, &frame, 4 );
			k+=4;
			memcpy( buffer + k, &size, 4 );
			k+=4;
			memcpy( buffer + k, &src32, 4 );
			k+=4;

			bufferSize = PacketHeaderSize;
		}
	}

	//Searching and parsing header
	int findHeader( char *data, int len ) {
		for (int k=0; k<len - PacketHeaderSize; k++) {
			if ( data[k] == PacketMarker[0] ) {
				bool ok = true;
				for (int i=1; i<PacketMarkerSize; i++) {
					if ( data[k+i] != PacketMarker[i] ) {
						ok = false;
						break;
					}
				}
				if ( ok ) {	ok = parse( data + k ); }
				if ( ok ) {
					return k;
				}
			}
		}
		return -1;
	}

private:
	bool parse( char *data )	//It is suggested here that size of data is enough for parsing
	{
		int k=0;
		memcpy( buffer + k, &data + k, PacketMarkerSize );
		k += PacketMarkerSize;
		memcpy( &frame, data + k, 4 );
		k+=4;
		memcpy( &size, data + k, 4 );
		k+=4;
		memcpy( &src32, data + k, 4 );
		k+=4;
		return ( frame >= 0 && size >= 0 && size < 10000000 && src32 >= 0 );	//TODO Parameter "10000000" 
	}
};

//-------------------------------------------------------------------
void pbNetworkSenderSync::setup( const string &addr, int port, int packetSize )
{
	_addr = addr;
	_port = port;
	_packetSize = packetSize;

	tcpClient.TCPClientRef().SetTimeoutSend( 1 );	//TODO Parameter "1" - wait for send timeout
	tcpClient.TCPClientRef().SetTimeoutAccept( 1 );	//TODO Parameter
	reconnect();
}

//-------------------------------------------------------------------
void pbNetworkSenderSync::close()
{
	if ( connected() ) {
		tcpClient.close();
	}
}

//-------------------------------------------------------------------
void pbNetworkSenderSync::reconnect()
{
	cout << "Reconnect sender " << _addr << ", port " << _port << endl;
	bool blocking = true;
	_connected = tcpClient.setup( _addr, _port, blocking);		
	_connectTime = ofGetElapsedTimef();
	if ( _connected ) { cout << " ok" << endl; }
	else { cout << " failed" << endl; }
}

//-------------------------------------------------------------------
void pbNetworkSenderSync::update()
{
	//Reconnecting
	if ( !connected() ) {			
		float deltaTime = ofGetElapsedTimef() - _connectTime;
		if( deltaTime > 1.0f ) {			//TODO Parameter - reconnecting time
			reconnect();
		} 
	}
}

//-------------------------------------------------------------------
bool pbNetworkSenderSync::send( unsigned char *data, int size, int frameNumber )
{
	update();	
	bool res = connected();
	//Header
	if ( res ) {
		PacketHeader header;
		header.setup( frameNumber, size, 0, true );
		res = tcpClient.sendRawBytes( header.buffer, header.bufferSize );
	}
	//Data
	int N = 0;
	if ( res ) {
		while ( N < size && res ) {
			int n = size - N;
			n = min( n, _packetSize );
			res = tcpClient.sendRawBytes( (char *)data + N, n );
			N += n;
		}
	}

	if ( !res && connected () ) {		//If sending was failed, then reconnect
		cout << "Data send error..." << endl;
		tcpClient.close();
		_connected = false;
	}

	return res;
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
void pbNetworkReceiver::setup( int port, int packetSize, bool threaded )		
{
	_threaded = threaded;
	_wantRestart = false;

	_port = port;
	_packetSize = packetSize;

	_frame = -1;
	_size = 0;

	maxN = 1000000;		//TODO Parameter
	_buffer.resize( maxN );
	_N = 0;

	_data.resize( maxN );

	startTCP();

	if ( _threaded ) {
		startThread( true, false );   //blocking, verbose
	}
}

//-------------------------------------------------------------------
void pbNetworkReceiver::startTCP()
{
	cout << "pbNetworkReceiver - start receiver, port " << _port << endl;
	bool blocking = true;
	TCP.setup(_port, blocking);
	int timeoutReceiveSec = 1;
	TCP.TCPServerRef().SetTimeoutReceive( timeoutReceiveSec );	
}

//-------------------------------------------------------------------
void pbNetworkReceiver::close()
{
	if ( _threaded ) {
		stopThread();		//TODO - it crashes application!
	}
	TCP.close();
}

//-------------------------------------------------------------------
void pbNetworkReceiver::restart()	
{
	_wantRestart = true;
}

//-------------------------------------------------------------------
void pbNetworkReceiver::threadedFunction()
{
	while( isThreadRunning() != 0 ){
		//Receive
		receive0();

		//Restarting - just disconnect all clients
		if ( _wantRestart ) {
			_wantRestart = false;
			for(int k = 0; k < TCP.getNumClients(); k++){
				if ( TCP.isClientConnected(k) ) { 
					disconnectClient( k );
				}
			}
		}
	}

}


//-------------------------------------------------------------------
void pbNetworkReceiver::receive()
{
	if ( !_threaded ) {
		receive0();
	}
}

//-------------------------------------------------------------------
//Shortening buffer to length newLen
void shiftBuffer( char *buffer, int &len, int newLen )
{
	if ( newLen < len ) {
		int start = len - newLen;
		for (int i=0; i<newLen; i++) {
			buffer[ i ] = buffer[ i + start ];
		}
		len = newLen;
	}
}

//-------------------------------------------------------------------
void pbNetworkReceiver::receive0()
{
	char *buffer = &_buffer[0];
	for(int k = 0; k < TCP.getNumClients(); k++){
		if ( !TCP.isClientConnected(k) ) { 
			continue;
		}

		int free = maxN - _N;
		if ( free > 0 ) {
			free = min( free, _packetSize );
			int rec = TCP.receiveRawBytes( k, (char *)(buffer + _N), free ); 
			if ( rec >= 0 ) {
				_N += rec;		
				//cout << "rec " << rec << endl;
				//Searching header
				PacketHeader header;
				int headerPos = header.findHeader( (char *)buffer, _N );
				if ( headerPos >= 0 ) {

					//cout << "reading frame " << header.frame << endl;
					
					//Header is found, now receive data

					int headerEnd = headerPos + PacketHeaderSize;
					int N = _N - headerEnd;

					//Shifting buffer to data begin
					shiftBuffer( buffer, _N, N );

					int size = header.size;

					float lastTime = ofGetElapsedTimef();	//Time of last successfull receiving
					while ( _N < size ) {
						rec = TCP.receiveRawBytes( k, (char *)(buffer + _N), free ); 
						if ( rec > 0 ) {
							_N += rec;
							lastTime = ofGetElapsedTimef();
						}
						else {
							float time = ofGetElapsedTimef();
							if ( time >= lastTime + 1.0 ) {		//TODO Parameter - connection is lost
								cout << "Reading data error frame " << header.frame << endl;
								break;
							}
						}
					}
					if ( _N >= size ) {
						//Data was read successfull
						memcpy( &_data[0], buffer, size );
						_frame = header.frame;
						_size = header.size;
						//cout << _frame << endl;
					}
				}
				else {
					//Shoretinig current buffer to continue searching for header
					shiftBuffer( buffer, _N, PacketHeaderSize );
				}


			}
			else {
				cout << "Network: Receive error - no data" << endl;
				disconnectClient( k );
				_N = 0;						//Reset read data
				return;						
			}
		}
	}
}

//-------------------------------------------------------------------
void pbNetworkReceiver::disconnectClient( int id )	//отключить клиента
{
	cout << "\tDisconnect client " << id + 1 << endl;
	if ( id < TCP.getNumClients() ) {
		TCP.disconnectClient( id );
	}
}

//-------------------------------------------------------------------
