#include "testApp.h"

ofImage image;		//Declare image object

//--------------------------------------------------------------
void testApp::setup(){
	image.loadImage("sunflower-transp.png");	
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	//Set up white background
	ofBackground( 255, 255, 255 );

	//Draw two images without color modulation
	//(but using alpha channel by default)
	ofSetColor( 255, 255, 255, 255 );
	image.draw( 100, 0 );
	image.draw( 250, 0 );

	//Draw half-transparent image
	ofSetColor( 255, 255, 255, 128 );
	image.draw( 400, 0 );
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