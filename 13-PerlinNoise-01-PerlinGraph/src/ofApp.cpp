#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255 );

	ofSetColor( 0, 0, 0 );	
	for (int x=0; x<1000; x++) {
		float t = x * 0.01;
		float y = ofNoise( t );				//Perlin noise computing
		//float y = ofNoise( t + 493.0 );	//Try this variant too
	
		ofLine( x, 300, x, 300 - y * 300 );
	}

	//Bounding rectangle
	ofNoFill();
	ofRect( 0, 0, 1000, 300);
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