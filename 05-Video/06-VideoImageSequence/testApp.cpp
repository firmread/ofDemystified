#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	//Load background
	backVideo.loadMovie( "elephant.mov" );
	backVideo.play();

	//Set the screen size equal to the backVideo dimensions
	ofSetWindowShape( backVideo.width, backVideo.height );

	//Read image sequence from the folder

	//1. Create object for reading folder contents
	ofDirectory dir;

	//2. Get the number of files in the folder data/woolCloudSeq
	int n = dir.listDir("woolCloudSeq");

	//3. Set the array size to n
	seq.resize( n );	

	//4. Load images
	for (int i=0; i<n; i++) {
		//Getting i-th file name
		string fileName = dir.getPath( i );	

		//Load i-th image
		ofLoadImage( seq[i], fileName );
	}
}

//--------------------------------------------------------------
void testApp::update(){
	backVideo.update();	//Decode the new frame if needed
}

//--------------------------------------------------------------
void testApp::draw(){
	//Draw background video
	ofSetColor( 255, 255, 255 );
	backVideo.draw(0,0);				

	// Calculate sequence frame number i,
	//based on the current time

	//1. Get the number of seconds from application start
	float time = ofGetElapsedTimef();

	//2. Get the size of image sequence
	int n = seq.size();

	//3. Calculate the sequence duration
	//Our sequence will render 12 frames per second, so:
	float duration = n / 12.0;		

	//4. Calculate looped playing position in sequence,
	//in range [0..duration]
	float pos = fmodf( time, duration );

	//5. Convert pos in the frame number
	int i = int( pos / duration * n );

	//Wool cloud will move, so calculate its position
	//depending on time
	float x = ofNoise( time * 0.5 + 10.0 ) * ofGetWidth();
	float y = ofNoise( time * 0.3 + 20.0 ) * ofGetHeight() / 4.0;

	//Enable alpha blending
	ofEnableAlphaBlending();	

	//Draw a sequence frame centered at (x,y)
	seq[i].setAnchorPercent( 0.5, 0.5 );
	seq[i].draw( x, y );
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