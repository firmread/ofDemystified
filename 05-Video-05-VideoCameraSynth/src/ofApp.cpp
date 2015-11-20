#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Show in console all details and warnings on the grabbing
	grabber.setVerbose(true);	

	//Select camera by its id in system
	grabber.setDeviceID(0);		

	//Select desired camera frame rate
	grabber.setDesiredFrameRate(30);	

	//Start grabbing with desired frame width and height
	grabber.initGrabber(640,480);	

	//Show in the console list of connected cameras
	//if you camera did not connect, please see the list
	grabber.listDevices();		


	//Load and start prerecorded movie to play
	video.loadMovie( "../../../Video/handsTrees.mov" );
	video.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();		//Update grabber state
	if ( grabber.isFrameNew() ) {	//Check for new frame		
		//Create image using grabber and video frames
		synthesizeImage();
	}
	video.update();	//Update video state
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Set white background
	ofBackground( 255, 255, 255 );	

	//Draw processed image
	ofSetColor( 255, 255, 255 );
	image.draw( 0, 0 );

	//Draw live unchanged video frame at right,
	//in a half of its size
	grabber.draw( image.getWidth() + 10, 0, 320, 240 );
}

//--------------------------------------------------------------
void ofApp::synthesizeImage(){

	//Initialize output pixels
	ofPixels pixels = grabber.getPixelsRef();	

	//Get pixel arrays for grabber and video
	ofPixels &pixelsGrab = grabber.getPixelsRef();
	ofPixels &pixelsVideo = video.getPixelsRef();

	//Get width and height for formulas shortening
	int w = pixelsGrab.getWidth();
	int h = pixelsGrab.getHeight();

	//We proceed only if video and grabbing frames
	//have equal sizes
	if ( !(w == pixelsVideo.getWidth()
		&& h == pixelsVideo.getHeight()) ) {
			return;
	}

	//Scan pixels
	for (int y=0; y<h; y++) {
		for (int x=0; x<w; x++) {
			//Get grabber color
			ofColor colorGrab = pixelsGrab.getColor( x, y );

			//Shift x-coordinate by red component
			int x1 = x + ( colorGrab.r - 127 );	

			//Truncate x1 to bounds
			x1 = ofClamp( x1, 0, w-1 );

			//Get color of pixel (x1, y) from video
			ofColor color = pixelsVideo.getColor( x1, y );

			//Set color to output pixel (x, y)
			pixels.setColor( x, y, color );
		}
	}
	//Update image pixels
	image.setFromPixels( pixels );
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
