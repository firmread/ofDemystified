#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	video.loadMovie( "../../../Video/handsTrees.mov" );	//Load video file

	//Play video with 1/4 of its normal speed
	//for better seeing slit-scan effect
	video.setSpeed( 0.25 );

	video.play();	//Start video to play	

	N = 150;		//Set buffer size
}

//--------------------------------------------------------------
void testApp::update(){
	video.update();		//Decode the new frame if needed

	//Do computing only if a new frame was obtained
	if ( video.isFrameNew() ) {		
		//Push the new frame to the beginning of the frame list
		frames.push_front( video.getPixelsRef() );

		//If number of buffered frames > N,
		//then pop the oldest frame
		if ( frames.size() > N ) {
			frames.pop_back();
		}
	}
	//It is possible that video player did
	//not finish decoding the first frame at first testApp::update()
	//calling, so we need check, if there are frames
	if ( !frames.empty() ) {
		//Now constructing the output image in imagePixels

		//If imagePixels is not initialized yet, then initialize
		//it by copying from any frame.
		//This is the simplest way to create a pixel array
		//of the same size and type
		if ( !imagePixels.isAllocated() ) {
			imagePixels = frames[0];
		}

		//Getting video frame size for formulas simplification
		int w = frames[0].getWidth();
		int h = frames[0].getHeight();

		//Scan all the pixels
		for (int y=0; y<h; y++) {
			for (int x=0; x<w; x++) {

				//Get "slit" pixel color
				ofColor color = getSlitPixelColor( x, y );

				//Set pixel to image pixels
				imagePixels.setColor( x, y, color );
			}
		}
		//Set new pixels values to the image
		image.setFromPixels( imagePixels );
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(255, 255, 255);	//Set white background

	//Draw image
	ofSetColor( 255, 255, 255 );		
	image.draw(0,0);	
}

//--------------------------------------------------------------
ofColor testApp::getSlitPixelColor( int x, int y ){
	//Calculate the distance from (x,y) to the current 	
	//mouse position mouseX, mouseY							
	float dist = ofDist( x, y, mouseX, mouseY );

	//Main formula for connecting (x,y) with frame number
	float f = dist / 8.0;
	//Here "frame number" is computer as a float value.
	//We need it for getting a "smooth result"
	//by interpolating colors later

	//Compute two frame numbers surrounding f
	int i0 = int( f );
	int i1 = i0 + 1;

	//Compute weights of the frames i0 and i1
	float weight0 = i1 - f;
	float weight1 = 1 - weight0;

	//Limiting frame numbers by range from 0 to n=frames.size()-1
	int n = frames.size() - 1;
	i0 = ofClamp( i0, 0, n );
	i1 = ofClamp( i1, 0, n );

	//Getting the frame colors
	ofColor color0 = frames[ i0 ].getColor( x, y );
	ofColor color1 = frames[ i1 ].getColor( x, y );

	//Interpolate colors - this is the function result
	ofColor color = color0 * weight0 + color1 * weight1;

	return color;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
