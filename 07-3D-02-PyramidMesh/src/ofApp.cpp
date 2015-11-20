#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
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
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
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