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
	ofSetColor( 0, 0, 0 );              //Set black color

	//ofNoFill();                         //Draw shapes unfilled
	//ofSetLineWidth( 7 );                //Draw thick lines
	//ofSetCircleResolution( 40 );        //Increase smoothing of the circle

	ofCircle( 300, 100,  40 );           //Blossom
	ofLine( 300, 100,  300, 400 );       //Stem
	ofTriangle( 300, 270,  300, 300,  200, 220 ); //Left leaf
	ofTriangle( 300, 270,  300, 300,  400, 220 ); //Right leaf
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