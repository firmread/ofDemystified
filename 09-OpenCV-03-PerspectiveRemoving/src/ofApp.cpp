#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofImage imageOf;
	imageOf.loadImage( "../../../Content/table.png" );
	image.setFromPixels( imageOf.getPixelsRef() );
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255, 255, 255);	//Set the background color
	
	ofSetColor( 255, 255, 255 );	

	image2 = image;
	
	//Points:
	//	  A----B
	//	 /      \
	//	D--------C

	image2.warpPerspective( 
		ofPoint( 192, 286 ),			//A
		ofPoint( 742, 188 ),			//B
		ofPoint( 950, 489 ),			//C
		ofPoint( 215, 665 ) );			//D

	image2.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
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
