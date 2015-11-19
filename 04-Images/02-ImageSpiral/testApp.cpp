#include "testApp.h"

ofImage image;		//Declare image object

//--------------------------------------------------------------
void testApp::setup(){
	//Load image file
	image.loadImage("../../../Images/sunflower.png");	
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
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
