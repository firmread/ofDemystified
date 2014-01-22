#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
}

//--------------------------------------------------------------
void testApp::update(){


}

//--------------------------------------------------------------
void testApp::draw(){
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