#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofImage imageOf;	//Temporary image for loading from the file
	imageOf.loadImage( "../../../Content/sunflower.png" );	//Load image from
	//the file

	//Set image pixels
	image.setFromPixels( imageOf.getPixelsRef() );

	//Convert to a grayscale image
	grayImage = image;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
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
