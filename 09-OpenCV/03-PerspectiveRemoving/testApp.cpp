#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofImage imageOf;
	imageOf.loadImage( "table.png" );
	image.setFromPixels( imageOf.getPixelsRef() );
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
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
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

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
