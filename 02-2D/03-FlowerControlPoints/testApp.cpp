#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
}

//--------------------------------------------------------------
void testApp::update(){
	//Set control points values
	stem0 = ofPoint( 300, 100 );
	stem1 = ofPoint( 300, 270 );
	stem2 = ofPoint( 300, 300 );
	stem3 = ofPoint( 300, 400 );

	leftLeaf = ofPoint( 200, 220 );
	rightLeaf = ofPoint( 400, 220 );

	//Move leftLeaf and rightLeaf by shifting their on some values

	//Compute shift values
	float time = ofGetElapsedTimef();
	float shiftX = sin(time * M_TWO_PI * 0.33 + 33.1 ) * 30.0;	
	//0.33 - speed, 33.1 - arbitrary phase shift, 30.0 - amplitude of shift in x

	float shiftY = sin(time * M_TWO_PI * 0.25 + 54.2) * 15.0;
	//0.25 - speed, 54.2 - arbitrary phase shift, 30.0 - amplitude of shift in y

	//Symmetrically shifting 
	leftLeaf += ofPoint( shiftX, shiftY );
	rightLeaf += ofPoint( -shiftX, shiftY );
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );      	//Set white background
	ofSetColor( 0, 0, 0 );					//Set black color

	//ofSetLineWidth( 7 );					//Draw thick lines
	//ofSetCircleResolution( 40 );			//Increase smoothing of the circle

	ofCircle( stem0, 40 );					//Blossom
	ofLine( stem0, stem3 );					//Stem
	ofTriangle( stem1, stem2, leftLeaf );	//Left leaf
	ofTriangle( stem1, stem2, rightLeaf );	//Right leaf
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