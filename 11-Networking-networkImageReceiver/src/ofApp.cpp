#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	//Set image size
	w = 320; //640;
	h = 240; //480;
	size = w * h * 3;

	//Set window title and size
	ofSetWindowTitle( "Network image receiver" );
	ofSetWindowShape( w + 40, h + 100 );

	//Starting network
	int port = 12345;
	int packetSize = 1024;

	_receiver.setup( port, packetSize, true );
	_frameId = -1;
    
    //FPS counter
    _receiveLastTime = 0;
    _receiveCount = 0;
    _receiveFPS = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

    if ( _receiver.frame() != _frameId ) {  //Check if new frame was received
		_frameId = _receiver.frame();
		if ( _receiver.size() == size ) {
            //Set received data to image
			image.setFromPixels(  &_receiver.data()[0], w, h, OF_IMAGE_COLOR );
		}
		else {
			cout << "ERROR: Network received data with bad size, check image sizes" << endl;
		}
        
        //Update FPS counter
		_receiveCount++;
		float fpsUpdateSec = 1.0;	//Time in seconds for accumulating FPS
		float time = ofGetElapsedTimef();
		if ( time >= _receiveLastTime + fpsUpdateSec ) {
			_receiveFPS = _receiveCount / ( time - _receiveLastTime );
			_receiveLastTime = time;
			_receiveCount = 0;
		}
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 200, 200, 255 );

	//Draw received image
	if ( image.isAllocated() ) {
		ofSetColor( 255, 255, 255 );
		image.draw( 20, 20 );
	}
	
	//Print frame id and FPS
	ofSetColor( 0, 0, 0 );
	ofDrawBitmapString( "Received frame id = " + ofToString( _frameId ), 20, h + 40 );
	ofDrawBitmapString( "Receiving FPS = " + ofToString( _receiveFPS, 1 ), 20, h + 60 );
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