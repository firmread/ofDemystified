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