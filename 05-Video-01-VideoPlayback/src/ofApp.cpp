#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	video.loadMovie( "../../../Video/handsTrees.mov" );	//Load the video file
	video.play();					//Start the video to play	
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();					//Decode the new frame if needed
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255 );	//Set white background

	ofSetColor( 255, 255, 255 );
	video.draw( 0, 0 );				//Draw the current video frame
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
