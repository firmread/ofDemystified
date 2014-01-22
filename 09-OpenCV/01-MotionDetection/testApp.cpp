#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	video.loadMovie("handsTrees.mov");	//Load the video file
	video.play();						//Start the video to play
}

//--------------------------------------------------------------
void testApp::update(){
	video.update();		//Decode the new frame if needed
	//Do computing only if the new frame was obtained
	if ( video.isFrameNew() ) {
		//Store the previous frame, if it exists till now
		if ( grayImage.bAllocated ) {
			grayImagePrev = grayImage;
		}

		//Getting a new frame
		image.setFromPixels( video.getPixelsRef() );
		grayImage = image;	//Convert to grayscale image

		//Do processing if grayImagePrev is inited
		if ( grayImagePrev.bAllocated ) {
			//Get absolute difference
			diff.absDiff( grayImage, grayImagePrev );

			//We want to amplify the difference to obtain
			//better visibility of motion
			//We do it by multiplication. But to do it, we
			//need to convert diff to float image first
			diffFloat = diff;	//Convert to float image
			diffFloat *= 5.0;	//Amplify the pixel values

			//Update the accumulation buffer
			if ( !bufferFloat.bAllocated ) {
				//If the buffer is not initialized, then
				//just set it equal to diffFloat
				bufferFloat = diffFloat;
			}
			else {
				//Slow damping the buffer to zero
				bufferFloat *= 0.85;
				//Add current difference image to the buffer
				bufferFloat += diffFloat;
			}
		}	
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );	//Set the background color

	//Draw only if diffFloat image is ready.
	//It happens when the second frame from the video is obtained
	if ( diffFloat.bAllocated ) {
		//Get image dimensions
		int w = grayImage.width;	
		int h = grayImage.height;

		//Set color for images drawing
		ofSetColor( 255, 255, 255 );

		//Draw images grayImage,  diffFloat, bufferFloat
		grayImage.draw( 0, 0, w/2, h/2 );
		diffFloat.draw( w/2 + 10, 0, w/2, h/2 );
		bufferFloat.draw( 0, h/2 + 10, w/2, h/2 );

		//Draw the image motion areas

		//Shift and scale the coordinate system
		ofPushMatrix();
		ofTranslate( w/2+10, h/2+10 );
		ofScale( 0.5, 0.5 );

		//Draw bounding rectangle
		ofSetColor(0, 0, 0);
		ofNoFill();
		ofRect( -1, -1, w+2, h+2 );

		//Get bufferFloat pixels
		float *pixels = bufferFloat.getPixelsAsFloats();
		//Scan all pixels
		for (int y=0; y<h; y++) {
			for (int x=0; x<w; x++) {
				//Get the pixel value
				float value = pixels[ x + w * y ];
				//If value exceed threshold, then draw pixel
				if ( value >= 0.9 ) {
					ofRect( x, y, 1, 1 );
					//Rectangle with size 1x1 means pixel
					//Note, this is slow function, 
					//we use it here just for simplicity
				}
			}
		}
		ofPopMatrix();	//Restore the coordinate system
	}
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
