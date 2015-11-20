#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	video.loadMovie( "../../../Video/handsTrees.mov" );	//Load video file
	video.play();							//Start video to play	

	//Fill the table by random values from 0 to 255
	for ( int i=0; i<16; i++ ) {
		table[i] = ofRandom( 0, 255 );
	}	
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();		//Decode the new frame if needed

	//Do computing only if a new frame was obtained
	if ( video.isFrameNew() ) {		
		//Getting pixels
		ofPixels pixels = video.getPixelsRef();

		//Scan all the pixels
		for (int y=0; y<pixels.getHeight(); y++) {
			for (int x=0; x<pixels.getWidth(); x++) {
				//Getting pixel (x,y) color
				ofColor col = pixels.getColor( x, y );

				//Change color components of col
				//using table
				col.r = table[ col.r/16 ];
				col.g = table[ col.g/16 ];
				col.b = table[ col.b/16 ];

				//Set the color back to the pixel (x,y)
				pixels.setColor( x, y, col );
			}
		}

		//Set pixel array to the image
		image.setFromPixels( pixels );
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255 );	//Set white background

	//Draw the image
	ofSetColor( 255, 255, 255 );		
	image.draw(0,0);	
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
