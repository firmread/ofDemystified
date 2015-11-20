#include "ofApp.h"

ofTexture		texture;
ofPoint p[4];			//Corners
int ind = 0;			//Index of selected corner, 0..3

void ofApp::setup(){
	//Load texture image
	ofLoadImage( texture, "../../../Images/sunflower.png" );	

	//Set up initial corners
	p[0].x = 100;	p[0].y = 100;
	p[1].x = 300;	p[1].y = 100;
	p[2].x = 300;	p[2].y = 300;
	p[3].x = 100;	p[3].y = 300;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255 );

	ofSetColor( 255, 255, 255 );

	//Draw texture by specifying its target corners points
	texture.draw( p[0], p[1], p[2], p[3] );	
}

//--------------------------------------------------------------
//Process keys
void ofApp::keyPressed(int key){
	//Select corner to edit by keys 1,2,3,4
	if ( key == '1' ) { ind = 0; }
	if ( key == '2' ) { ind = 1; }
	if ( key == '3' ) { ind = 2; }
	if ( key == '4' ) { ind = 3; }

	//Move selected corner by cursor keys
	if ( key == OF_KEY_LEFT ) { p[ ind ].x -= 10; }
	if ( key == OF_KEY_RIGHT ) { p[ ind ].x += 10; }
	if ( key == OF_KEY_UP ) { p[ ind ].y -= 10; }
	if ( key == OF_KEY_DOWN ) { p[ ind ].y += 10; }
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
