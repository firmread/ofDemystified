#include "ofApp.h"

ofImage image;	 	//Declare image object

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
	//Creating image

	int w = 512;  //Image width
	int h = 512;  //Image height

	//Allocate array for filling pixels data
	unsigned char *data = new unsigned char[w * h * 4];

	//Fill array for each pixel (x,y)
	for (int y=0; y<h; y++) {
		for (int x=0; x<w; x++) {
			//Compute preliminary values,
			//needed for our pixel color calculation:

			//1. Time from application start
			float time = ofGetElapsedTimef();

			//2. Level of hyperbola value of x and y with
			//center in w/2, h/2
			float v = ( x - w/2 ) * ( y - h/2 );

			//3. Combining v with time for motion effect
			float u= v * 0.00025 + time;
			//Here 0.00025 was chosen empirically

			//4. Compute color components as periodical 
			//functions of u, and stretched to [0..255]
			int red = ofMap( sin( u ), -1, 1, 0, 255 );
			int green = ofMap( sin( u * 2 ), -1, 1, 0, 255 );
			int blue = 255 - green;
			int alpha = 255;  //Just constant for simplicity


			//Fill array components for pixel (x, y):
			int index = 4 * ( x + w * y );
			data[ index ] = red;
			data[ index + 1 ] = green;
			data[ index + 2 ] = blue;
			data[ index + 3 ] = alpha;
		}
	}

	//Load array to image
	image.setFromPixels( data, w, h, OF_IMAGE_COLOR_ALPHA );

	//Array is not needed anymore, so clear memory
	delete[] data;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255 );	//Set up white background
	ofSetColor( 255, 255, 255 );	//Set color for image drawing
	image.draw( 0, 0 );				//Draw image
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