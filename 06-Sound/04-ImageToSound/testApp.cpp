#include "testApp.h"

/**********  WARNING  *********************** 
To avoid the hazard of damaging your ears, 
do not listen the project's output sound with headphones.
This project uses low-level audio output, so due 
possible errors in software it can suddenly 
generate clicks and very loud sounds.
********************************************/

//Constants
const int grabW = 1024;                 //Width of the camera frame
const int grabH = 768;                  //Height of the camera frame
const float duration = 0.25;            //Duration of the recorded sound in seconds
const int sampleRate = 44100;           //Sample rate of sound
const int N = duration * sampleRate;     //Size of the PCM buffer of sound sample

const float volume = 0.5;	//Output sound volume
const int Y0 = grabH * 0.5;	//y-position of the scan line

//Variables
vector<float> arr; 		//Temporary array of pixels brightness, mapped to range [-1,1]
vector<float> buffer;  //PCM buffer of sound sample
int playPos = 0;		//The current position of the buffer playing

//--------------------------------------------------------------
void testApp::setup(){
	//Set arrays sizes and fill these by zeros
	arr.resize( grabW, 0.0 ); 
	buffer.resize( N, 0.0 );  

	//Start camera
	grabber.initGrabber( grabW, grabH );

	//Start the sound output
	soundStream.setup( this, 2, 0, sampleRate, 512, 4 );
}

//--------------------------------------------------------------
void testApp::update(){	
	grabber.update();			//Update camera
	if ( grabber.isFrameNew() ) {	//Check for new frame
		
		//Get pixels of the camera image
		ofPixels &pixels = grabber.getPixelsRef();
        
        //Check image size
        if ( pixels.getWidth() != grabW || pixels.getHeight() != grabH ) {
            return;
        }
        
		//Read pixels brightness from the central line of the image
		for (int x=0; x<grabW; x++) {
			//Get the pixel brightness
			float v = pixels.getColor( x, Y0 ).getLightness();
			//v lies in [0,255], convert it to [-1,1]
			arr[x] = ofMap( v, 0, 255, -1, 1, true );
		}
                
        //Stretch arr to buffer (having size N), using linear interpolation
        for (int i=0; i<N; i++) {
            float pos = float(i) * grabW / N;   //Get float position in range [0, grabW]
            int pos0 = int( pos );              //Get left index
            int pos1 = min( pos0 + 1, N-1 );    //Getright index
            //Interpolate
            buffer[i] = ofMap( pos, pos0, pos1, arr[pos0], arr[pos1] );
        }

		//Shift the buffer values to have a mean value
		//equal to zero
		//Compute a mean value of buffer
		float mean = 0;
		for (int i=0; i<N; i++) {
			mean += buffer[i];
		}
		mean /= N;
		//Shift the buffer by mean value
		for (int i=0; i<N; i++) {
			buffer[i] -= mean;
		}        
        
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );	//Set the background color
	//Draw a camera frame
	ofSetColor( 255, 255, 255 );
	grabber.draw( 0, 0 );
	//Draw the scan line area
	ofNoFill();
	ofSetColor( 255, 255, 0 );
	ofRect( 0, Y0 - 1, N, 3 );

	//Draw the current buffer as a graph
	ofSetColor( 255, 255, 255 );
	ofFill();
	ofRect( 0, 0, grabW, 100 );
	ofSetColor( 0 );
	for (int x=0; x<grabW; x++) {
        int i = float(x) * N / grabW;   //Find position in buffer
		ofLine( x, 50, x, 50 - buffer[i] * 50 );
	}
}

//--------------------------------------------------------------
void testApp::audioOut(
		float *output, int bufferSize, int nChannels )
{
	for (int i=0; i<bufferSize; i++) {
		//Push current audio sample value from buffer
		//into both channels of output.
		//Also global volume value is used
		output[ 2*i ] = output[ 2*i + 1 ]
			= buffer[ playPos ] * volume;
		//Shift to the next audio sample
		playPos++;		
		//When the end of buffer is reached, playPos sets to 0
		//So we hear looped sound
		playPos %= N;	
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}