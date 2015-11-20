#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	//Depth camera setup
	openNIDevice.setup();
	openNIDevice.addDepthGenerator();
	openNIDevice.addImageGenerator();
	openNIDevice.setRegister(true);	//Enable alignment
	//of depth and color images
	openNIDevice.start();			//Start depth camera to capture

	//Set up drawing variables
	W = 1024;					//Desired screen size
	H = 768;
	outPixels.allocate( W, H, OF_IMAGE_GRAYSCALE );
	calibrating = true;		//Set calibrating mode at start
	shift = ofPoint( 100, 200 );	//The value of shifting
	//camera's image from the corner of the screen

	//Set full screen mode
	ofSetWindowShape( W, H );
	ofSetFullscreen( true );

}

//--------------------------------------------------------------
void ofApp::update(){

	openNIDevice.update();		//Update depth camera
	if ( !calibrating && corners.size() == 4 ) {
		//Analyze depth

		//Get current depth image
		ofShortPixels &input = openNIDevice.getDepthRawPixels();

		//Process pixels
		int w = input.getWidth();
		int h = input.getHeight();
		int minV = 30;		//Minimal distance in mm
		int maxV = 150; 		//Maximal distance in mm
		for (int Y=0; Y<H; Y++) {
			for (int X=0; X<W; X++) {
				//Process pixel (X, Y)

				//Transform screen coordinates (X, Y) 
				//to depth image coordinates (x, y)
				float a = float(X) / W;
				float b = float(Y) / H;
				ofPoint p =
					(1-a) * (1-b) * corners[0]
				+ a * (1-b) * corners[1]
				+ a * b * corners[2]
				+ (1-a) * b * corners[3];

				int x = int( p.x );
				int y = int( p.y );

				if ( x >= 0 && x < w && y >= 0 && y < h ) {
					//Getting depth values
					int inputZ = input.getPixels()[ x + w * y ];	
					int backgroundZ = backgroundDepth.getPixels()[ x + w * y ];

					int delta;
					//Check for zero values - it means that depth camera
					//does not compute distance in the pixel
					if ( inputZ != 0 && backgroundZ != 0 ) {
						delta = backgroundZ - inputZ;
					}
					else {
						delta = -1;
					}
					//Output value
					if ( ofInRange( delta, minV, maxV ) ) {	
						int value = ofMap( delta, minV, maxV, 0, 255, true );
						outPixels.getPixels()[ X + W * Y ] = value;
					}
				}


			}
		}
		outImage.setFromPixels( outPixels );
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground( 255, 255, 255 );	//Set white background

	if ( calibrating ) {	

		//Draw color and depth image
		ofSetColor( 255, 255, 255 );
		int w = openNIDevice.getWidth();
		int h = openNIDevice.getHeight();
		openNIDevice.drawImage( shift.x, shift.y );
		openNIDevice.drawDepth( shift.x+w+20, shift.y, w/2, h/2 );

		//Draw corners
		ofSetColor( 255, 0, 0 );
		ofFill();
		int n = corners.size();
		for (int i=0; i<n; i++) {
			ofCircle( corners[i] + shift, 10 );
		}
		if ( n == 4 ) {
			for (int i=0; i<n; i++) {
				ofLine( corners[i] + shift,
					corners[(i+1)%n] + shift );
			}
		}
	}
	else {
		//Show current drawing
		ofSetColor( 255, 255, 255 );
		outImage.draw( 0, 0 );
	}

}

//--------------------------------------------------------------
void ofApp::exit(){
	openNIDevice.stop();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if ( key == ' ' ) {
		calibrating = !calibrating;
		if ( !calibrating ) {	//Store background
			backgroundDepth = openNIDevice.getDepthRawPixels();
		}
	}
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
	if ( calibrating && corners.size() < 4 ) {
		corners.push_back( ofPoint( x, y ) - shift );
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

