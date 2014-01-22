#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	video.loadMovie( "handsTrees.mov" );	//Load the video file
	video.play();					//Start the video to play	
}

//--------------------------------------------------------------
void testApp::update(){
	video.update();					//Decode the new frame if needed
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );	//Set white background

	ofSetColor( 255, 255, 255 );
	video.draw( 0, 0 );				//Draw the current video frame
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