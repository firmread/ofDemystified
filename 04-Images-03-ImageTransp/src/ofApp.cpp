#include "ofApp.h"

ofImage image;		//Declare image object

//--------------------------------------------------------------
void ofApp::setup(){
	image.loadImage("../../../Images/sunflower-transp.png");	
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
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
void ofApp::keyPressed(int key){

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
