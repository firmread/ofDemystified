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