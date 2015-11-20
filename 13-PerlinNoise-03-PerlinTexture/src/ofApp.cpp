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
	float time = ofGetElapsedTimef();

	float scaleX = 0.007;		//1.0 / scaleX is coherence in x
	float scaleY = 0.008;		//1.0 / scaleY is coherence in y
	float posX0 = 593.2;
	float posY0 = 43.7;
	for (int y=0; y<500; y++) {
		for (int x=0; x<500; x++) {
			//Static texture variant
			float value = ofNoise( x*scaleX+posX0, y*scaleY+posY0 );	
			
			//Evolving texture variant
			//float value = ofNoise( x*scaleX+posX0, y*scaleY+posY0, time*0.1 + 445.6 );	

			ofSetColor( value*255, value*255, value*255 );
			ofRect( x, y, 1, 1 );	
			//We draw each pixel as 1x1 rectangle - it works very slowly.
			//For faster drawing use ofImage: 
			//1. fill unsigned char *data array,
			//2. load it in into ofImage image,
			//3. then draw it using image.draw(0, 0).
		}
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