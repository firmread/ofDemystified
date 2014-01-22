#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//Pyramid's base vertices with indices 0, 1, 2
	mesh.addVertex( ofPoint( -200, -100, -50 ) );
	mesh.addVertex( ofPoint( 200, -100, -50 ) );
	mesh.addVertex( ofPoint( 0, 200, 0 ) );

	//Pyramid's top vertex with index 3
	mesh.addVertex( ofPoint( 0, 0, 50 ) );

	//Vertices with indices 3, 2, 0
	mesh.addTriangle( 3, 2, 0 );

	//Vertices with indices 3, 1, 2
	mesh.addTriangle( 3, 1, 2 ); 

	//Vertices with indices 3, 0, 1
	mesh.addTriangle( 3, 0, 1 );

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableDepthTest();				//Enable z-buffering

	//Set a background
	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );

	ofPushMatrix();						//Store the coordinate system

	//Move coordinate center to screen's center
	ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );

	//Rotate the coordinate system
	float time = ofGetElapsedTimef();	//Get time in seconds
	float angle = time * 30;			//Rotate angle
	ofRotate( angle, 0, 1, 1 ); 

	ofSetColor( 0, 128, 0 );			//Set a dark green color
	mesh.draw();						//Draw the mesh

	ofPopMatrix();						//Restore the coordinate system
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