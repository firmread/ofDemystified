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
	//Set up white background
	ofBackground( 255, 255, 255 ); 	

	for (int i=0; i<20; i++) {
		ofPushMatrix();

		//Translate system coordinates to screen center
		ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );

		//Rotate coordinate system on i * 15 degrees
		ofRotate( i * 15 );			

		//Go right on 50 * i * 10 pixels
		//in rotated coordinate system
		ofTranslate( 50 + i * 10, 0 );

		//Scale coordinate system for descreasing drawing
		//image size
		float scl = 1.0 - i * 0.8 / 20.0;
		ofScale( scl, scl );	
		//scl decreases with i, so the images 
		//became gradually smaller

		//Draw image
		image.draw( -100, -100, 200, 200 );

		ofPopMatrix();
	}
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
