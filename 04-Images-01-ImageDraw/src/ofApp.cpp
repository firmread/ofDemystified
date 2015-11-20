#include "ofApp.h"

ofImage image;		//Declare image object

//--------------------------------------------------------------
void ofApp::setup(){
	//Load image file
	image.loadImage("../../../Images/sunflower.png");	
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Set up gray background
	ofBackground( 128, 128, 128 );

	//Draw image with top left corner x=100, y=50 pixels
	image.draw( 100, 50 );
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
