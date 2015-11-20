#include "ofApp.h"

/**********  WARNING  *********************** 
To avoid the hazard of damaging your ears, 
do not listen the project's output sound with headphones.
This project uses low-level audio output, so due 
possible errors in software it can suddenly 
generate clicks and very loud sounds.
********************************************/

//Constants
const int sampleRate = 44100;           //Sample rate of sound
const float duration = 0.25;            //Duration of the recorded sound in seconds
const int N = duration * sampleRate;    //Size of the PCM buffer

const float volume = 0.5;	//Output sound volume

//Variables
vector<float> buffer;		//PCM buffer of sound sample
int recPos = 0;				//Current recording position in the buffer
int playPos = 0;			//Current playing position in the buffer

int recordingEnabled = 1;	//Is recording enabled
int playingEnabled = 0;		//Is playing enabled


//--------------------------------------------------------------
void ofApp::setup(){
	//Set buffer size and fill it by zeros
	buffer.resize( N, 0.0 );  

	//Start the sound output in stereo (2 channels)
	//and sound input in mono (1 channel)
	soundStream.setup( this, 2, 1, sampleRate, 256, 4 );
}

//--------------------------------------------------------------
void ofApp::update(){	
	//Nothing here
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255 );	//Set the background color

	int w = 1024;	//Width of the sound visualization picture

	//Graph of the sound buffer
	ofSetColor( 0, 0, 0 );
	for (int x=0; x<w; x++) {
		int i = float(x) * N / w;   //Convert x to buffer's position        
		ofLine( x, 100, x, 100 - buffer[i] * 100 );
	}

	//Stripe image
	for (int x=0; x<w; x++) {
		int i = float(x) * N / w;   //Convert x to buffer's position
		float v = buffer[i];		//Get buffer value

		//Apply square-root transformation
		//and also shift by 0.2 to make the picture brighter
		v = ofSign( v ) * sqrt( fabs( v ) ) + 0.2;

		//Convert v to range [0,255]
		float col = ofMap( v, -1, 1, 0, 255, true );

		//Set color and draw vertical line
		ofSetColor( col, col, col );	
		ofLine( x, 200, x, 300 );
	}
}

//--------------------------------------------------------------
//Audio input
void ofApp::audioReceived(
	float *input, int bufferSize, int nChannels )
{
	//If recording is enabled by the user,
	//then store received data
	if ( recordingEnabled ) {	
		for (int i=0; i<bufferSize; i++) {
			buffer[ recPos ] = input[i];
			recPos++;
			//When the end of buffer is reached, recPos sets
			//to 0, so we record sound in a loop
			recPos %= N;
		}
	}
}

//--------------------------------------------------------------
//Audio output
void ofApp::audioOut(
	float *output, int bufferSize, int nChannels)
{
	//If playing is enabled by the user, then do output sound
	if ( playingEnabled ) {	
		for (int i=0; i<bufferSize; i++) {
			output[ 2*i ] = output[ 2*i+1 ]
			= buffer[ playPos ] * volume;
			playPos++;
			//When the end of buffer is reached, playPos sets
			//to 0, so we hear looped sound
			playPos %= N;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//Enable recording mode
	if ( key == '1' ) {
		recordingEnabled = 1; playingEnabled = 0;
	}

	//Enable playing mode
	if ( key == '2' ) {
		recordingEnabled = 0; playingEnabled = 1;
	}

	//Save screen image to the file
	if ( key == 's' ) {
		ofImage grab;
		grab.grabScreen( 0, 0, ofGetWidth(), ofGetHeight() );
		grab.saveImage( "grab.png" );
	}

	//Write the sound sample to raw-file
	if ( key == 'f' ) {	
		//Create a file for writing
		//Here "wb" means that we open binary file for writing
		FILE *file = fopen( ofToDataPath("sound.raw").c_str(), "wb" );	
		//Write the buffer into file
		fwrite( &buffer[0], N, sizeof( buffer[0] ), file );

		//Close the file
		fclose( file );
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}