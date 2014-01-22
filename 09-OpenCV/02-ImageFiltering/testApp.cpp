#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofImage imageOf;	//Temporary image for loading from the file
	imageOf.loadImage( "sunflower.png" );	//Load image from
	//the file

	//Set image pixels
	image.setFromPixels( imageOf.getPixelsRef() );

	//Convert to a grayscale image
	grayImage = image;
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 128, 128, 128 );		//Set the background color

	//Get image dimensions
	int w = image.width;
	int h = image.height;
	ofSetColor( 255, 255, 255 );	//Set a color for images drawing

	//Draw original image
	grayImage.draw( 0, 0, w, h );

	//Thresholding original image
	filtered = grayImage;			//Copy the image
	filtered.threshold( 128 );		//Thresholding original image using thresold 128
	filtered.draw( w+10, 0, w, h );	//Draw

	//Smoothing original image
	filtered = grayImage;			//Copy the image
	filtered.blurGaussian( 9 );		//Gaussian blurring with window size 9x9	
	filtered.draw( 0, h+10, w, h );	//Draw

	//Thresholding smoothed image
	filtered.threshold( 128 );		//Thresholding smoothed image using thresold 128
	filtered.draw( w+10, h+10, w, h );	//Draw
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
