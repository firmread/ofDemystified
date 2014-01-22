#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );

	ofSetColor( 0, 0, 0 );
	float time = ofGetElapsedTimef();
	for (int i=0; i<100; i++) {
		float ampX = ofGetWidth();
		float ampY = ofGetHeight();
		float speed = 0.1;
		float posX0 = i * 104.3 + 14.6;
		float posY0 = i * 53.3 + 35.2;

		//Get x and y using Perlin noise
		float x = ampX * ofNoise( time * speed + posX0 );	
		float y = ampY * ofNoise( time * speed + posY0 );
		ofCircle( x, y, 10 );
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