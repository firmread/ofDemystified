#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate( 60 );	//Set screen frame rate 

	//Allocate drawing buffer
	fbo.allocate( ofGetWidth(), ofGetHeight() );

	//Fill buffer with white color
	fbo.begin();
	ofBackground( 255, 255, 255 );
	fbo.end();

	//Initialize variables
	a = 0;
	b = 0;
	pos = ofPoint( ofGetWidth() / 2, ofGetHeight() / 2 );	//Screen center
	colorStep = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	fbo.begin();		//Begin draw to buffer
	for ( int i=0; i<200; i++ ) {
		draw1();
	}
	fbo.end();			//End draw to buffer
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );		//Set white background

	//Draw buffer
	ofSetColor( 255, 255, 255 );
	fbo.draw( 0, 0 );
}

//--------------------------------------------------------------
//Draw one line segment
void testApp::draw1(){
	//Change a
	a += b * DEG_TO_RAD;	
	//a holds values in radians, b holds values in degrees,
	//so when changing a we multiply b to DEG_TO_RAD constant

	//Change b
	b = b + 0.5;	
	//Also, try another values for incrementing b:
	//b = b + 5.4;
	//b = b + 5.5;
	//b = b + 4;			
	//b = b + 17;			
	//b = b + 21;			
	//Keep uncommented just one of these lines, and you see another curves.
	//Also, you can try you own values here.

	//Shift pos using angle a
	lastPos = pos;			//Store last pos value
	ofPoint d = ofPoint( cos( a ), sin( a ) );
	float len = 20;
	pos += d * len;

	//Change color each 100 steps
	if ( colorStep % 100 == 0 ) {
		//Generate random color
		color = ofColor( ofRandom( 0, 255 ), ofRandom( 0, 255 ), ofRandom( 0, 255 ) );
	}
	colorStep++;

	//Draw line segment
	ofSetColor( color );
	ofLine( lastPos, pos );        
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
	//Grab the screen image to file
	if ( key == ' ' ) {		
		ofImage image;				//Declare image object

		//Grab contents of the screen
		image.grabScreen( 0, 0, ofGetWidth(), ofGetHeight() );	

		image.saveImage( "screen.png" );	//Save image to file
	}
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