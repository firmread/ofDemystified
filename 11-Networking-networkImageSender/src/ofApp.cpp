#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

	//Set image size
	w = 320; //640;
	h = 240; //480;
	size = w * h * 3;

	//Set window title and size
	ofSetWindowTitle( "Network image sender" );
	ofSetWindowShape( w + 40, h + 100 );

	//Starting network
	int port = 12345;
	int packetSize = 1024;
	string addr = "127.0.0.1";

	_sender.setup( addr, port, packetSize );
	_frameId = 0;
	
	//Starting camera
	grabber.setVerbose(true);	
	grabber.setDeviceID(0);		
	grabber.setDesiredFrameRate(30);	
	grabber.initGrabber(w, h);		
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();	//Update grabber state
	
	if (grabber.isFrameNew()){	//Check for new frame
		//Send frame via network
		unsigned char * pixels = grabber.getPixels();
		_sender.send( pixels, size, _frameId++ );
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 200, 255, 200 );

	//Draw camera image
	ofSetColor( 255, 255, 255 );
	grabber.draw( 20, 20 );
	
	//Print frame id
	ofSetColor( 0, 0, 0 );
	ofDrawBitmapString( "Sent frame id = " + ofToString( _frameId ), 20, h + 40 );
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