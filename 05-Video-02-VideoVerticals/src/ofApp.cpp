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
	//Getting reference to the pixel array
	ofPixels &pixels = video.getPixelsRef();	

	//Define variables w, h equal to frame width and height
	int w = pixels.getWidth();
	int h = pixels.getHeight();

	//Scan center horizontal line
	for (int x=0; x<w; x++) {
		//Getting color of the center line
		ofColor color = pixels.getColor( x, h / 2 );

		//Draw a vertical line using this color
		ofSetColor( color );
		ofLine( x, 0, x, h );
	}
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
