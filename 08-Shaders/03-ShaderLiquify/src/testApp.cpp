#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	shader.load( "shaderVert.c", "shaderFrag.c" );

	fbo.allocate( ofGetWidth(), ofGetHeight() );
	image.loadImage( "sunflower.png" );	
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
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
	shader.setUniform1f( "time", time );	//Passing float parameter "time" to shader

	//Draw fbo image
	ofSetColor( 255, 255, 255 );
	fbo.draw( 0, 0 );

	shader.end();		//Disable the shader
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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

