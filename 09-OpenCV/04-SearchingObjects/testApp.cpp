#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	video.loadMovie("fruits.mov");	//Load the video file
	video.play();					//Start the video to play	
	drawMode = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	video.update();	//Decode the new frame if needed

	//Do computing only if the new frame was obtained
	if ( video.isFrameNew() ) {
		//Getting a new frame
		image.setFromPixels( video.getPixelsRef() );

		//Decimate image for speed-up processing
		if ( !imageDecimated.bAllocated ) {
			imageDecimated.allocate( image.width * 0.5,
				image.height * 0.5 );
		}
		imageDecimated.scaleIntoMe( image, CV_INTER_NN );

		//Convert to grayscale image
		grayImage = imageDecimated;	

		//Smoothing image
		blurred = grayImage;
		blurred.blurGaussian( 9 );

		//Store first frame to background image
		if ( !background.bAllocated ) {
			background = blurred;	
		}

		//Find difference of the frame and background
		diff = blurred;
		diff -= background;

		//Thresholding for obtaining binary image
		mask = diff;
		mask.threshold( 40 );
		//Here value 40 is the threshold parameter. 
		//It should be adjusted for good results when using another videos than in example.

		//Find contours
		contourFinder.findContours( mask, 10, 10000, 20, false );

		//Store objects' centers
		vector<ofxCvBlob>  &blobs = contourFinder.blobs;
		int n = blobs.size();	//Get number of blobs
		obj.resize( n );		//Resize obj array
		for (int i=0; i<n; i++) {
			obj[i] = blobs[i].centroid;	//Fill obj array
		}

		//Additional rendering - updates img if needed
		if ( drawMode == 1 ) {
			generateImg( mask.width, mask.height );
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	if ( drawMode == 0 ) {
		ofBackground(255, 255, 255);	//Set the background color
		int w = imageDecimated.width;
		int h = imageDecimated.height;
		ofSetColor( 255, 255, 255 );	//Set color for images drawing

		//Original decimated image
		imageDecimated.draw(0, 0, w, h);

		//Difference
		diff.draw( w+10, 0, w, h );

		//Thresholded
		mask.draw( 0, h+10, w, h );

		//Draw found contours
		contourFinder.draw( 0, h+10, w, h );

		//Draw centers over decimated image
		imageDecimated.draw(w+10, h+10, w, h);
		ofSetColor( 255, 255, 0 );
		ofSetLineWidth( 2 );
		for (int i=0; i<obj.size(); i++) {
			ofPoint p = obj[i] + ofPoint( w+10, h+10 );
			ofLine( p.x - 20, p.y, p.x + 20, p.y );
			ofLine( p.x, p.y - 20, p.x, p.y + 20 );
		}
		ofSetLineWidth( 1 );
	}
	else {
		//Additional rendering - draw generated image over original video
		ofEnableAlphaBlending();
		ofSetColor( 255, 255, 255 );
		video.draw( 0, 0 );
		img.draw( 0, 0, video.width, video.height );
	}
}

//--------------------------------------------------------------
//Additional rendering
void testApp::generateImg( int w, int h )
{
	if ( !img.bAllocated() ) {
		img.allocate( w, h, OF_IMAGE_COLOR_ALPHA );
	}

	ofPixels &pixels = img.getPixelsRef();

	//Generate image using object's centers
	for ( int y=0; y<h; y++) {
		for ( int x=0; x<w; x++ ) {
			float step = 15.0; //15;	
			float f = 0.;
			for (int i=0; i<obj.size(); i++) {
				ofPoint p = obj[i];
				float rad = 60;
				float val = 0;	
				float dist = ofDist( p.x, p.y, x, y );	

				//Circle function
				val = max( rad - abs( dist-rad ), 0.0f ); 		//2-peaks

				//Uncomment to try other shape:
				//Square function
				//val = max(abs( x - p.x ), abs( y - p.y ));

				f += val;
			}

			float val = fmodf( f, step * 2 ) / step;	
			val = 1-abs( 1-val );
			val = ofMap( val, 0.9, 1.0, 0, 255, true );
			pixels.setColor( x, y, ofColor( 255, 255, 255, val ) );
		}	
	}
	img.update();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if ( key == '1' ) {
		drawMode = 0;
	}
	if ( key == '2' ) {
		drawMode = 1;
	}
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
