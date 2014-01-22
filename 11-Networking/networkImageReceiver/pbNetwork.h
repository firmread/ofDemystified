#pragma once

/* Here declared classes for sending and receiving 
binary data fixed length using TCP.
For example, it can be used for image streaming.

Class pbNetworkSenderSync sends data in synchronous mode.
"Synchronous" means that its send() method returns only then sending occur.

Class pbNetworkReceiver receive data in synchronous or asynchronous mode.
"Asynchronous" means that it receives data in a separate thread, 
and inform your thread that new data is received.

-----------------------------------------------
NOTE: 
For example successful compiling this file in openFrameworks 0.8.0, 
you need to add two lines in the ofxNetwork addon:

1. In file addons/ofxNetwork/src/ofxTCPServer.h add 
the following line to class ofxTCPServer, in its public declarations section 
(for example, in line before "private:" keyword):

ofxTCPManager &TCPServerRef() { return TCPServer; }

2. In file addons/ofxNetwork/src/ofxTCPClient.h add 
the following line to class ofxTCPClient, in its public declarations section 
(for example, in line before "private:" keyword):

ofxTCPManager	&TCPClientRef() { return TCPClient; }

-----------------------------------------------

*/

#include "ofMain.h"
#include "ofxNetwork.h"

//Synchronous data sender
class pbNetworkSenderSync 
{
public:
	void setup( const string &addr, int port, int packetSize = 1024 );		//размер пакета
	void close();

	bool send( unsigned char *data, int dataSize, int frameNumber );
	void update();

	bool connected() { return _connected; }
private:
	ofxTCPClient tcpClient;
	int _port;
	string _addr;
	int _packetSize;

	bool _connected;
	float _connectTime;
	void reconnect();
};


//Data receiver, working as syncronous or asynchronous 
class pbNetworkReceiver : public ofThread{
public:
	void setup( int port, int packetSize = 1024, bool threaded = true );	
	//if threaded == true, it is asynchronous mode

	void close();

	int frame() { return _frame; }		//id of last received data
	int size()  { return _size; }		//size of last received data
	vector<unsigned char> &data() { return _data; }	//Last received data. 
				//Note, data.size() can be greater than size()

	void threadedFunction();

	void receive();
	void restart();		

private:
	bool _threaded;

	int _port;
	int _packetSize;

	ofxTCPServer TCP;					
	void disconnectClient( int id );	//Disconnect client

	int _frame;
	int _size;
	vector<unsigned char> _data;

	void receive0();
	vector<char> _buffer;
	int maxN;
	int _N;			//Current count of received bytes

	bool _wantRestart;
	void startTCP();
};
