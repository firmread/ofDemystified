#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load( "shaderVert.c", "shaderFrag.c" );

	fbo.allocate( ofGetWidth(), ofGetHeight() );
	image.loadImage( "sunflower.png" );	
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	//1. Drawing into fbo buffer
	fbo.begin();		//Start drawing into buffer

	//Draw something here just like it is drawn on the screen
	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
	ofSetColor( 255, 255, 255 );
	image.draw( 351, 221 );

	fbo.end();			//End drawing into buffer

	//2. Drawing to screen through the shader
	shader.begin();		//Enable the shader

	float time = ofGetElapsedTimef();
	shader.setUniform1f( "time", time );	//Pass float parameter "time" to shader

	//Draw fbo image
	ofSetColor( 255, 255, 255 );
	fbo.draw( 0, 0 );

	shader.end();		//Disable the shader
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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

