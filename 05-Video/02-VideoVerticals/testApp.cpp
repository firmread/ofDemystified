#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	video.loadMovie( "../../../Video/handsTrees.mov" );	//Load the video file
	video.play();					//Start the video to play	
}

//--------------------------------------------------------------
void testApp::update(){
	video.update();					//Decode the new frame if needed
}

//--------------------------------------------------------------
void testApp::draw(){
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
