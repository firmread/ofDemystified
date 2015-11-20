#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255 );      //Set white background

	//Changing brightness
	for ( int i=0; i<256; i++ ) {
		ofColor color = ofColor::red;	//Get red color
		color.setBrightness( i );		//Modify brightness
		ofSetColor( color );
		ofLine( i, 0, i, 50 );		
	}

	//Changing saturation
	for ( int i=0; i<256; i++ ) {
		ofColor color = ofColor::red;	//Get red color
		color.setSaturation( i );		//Modify saturation
		ofSetColor( color );
		ofLine( i, 80, i, 130 );
	}

	//Changing hue
	for ( int i=0; i<256; i++ ) {
		ofColor color = ofColor::red;	//Get red color
		color.setHue( i );				//Modify hue
		ofSetColor( color );
		ofLine( i, 160, i, 210 );
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