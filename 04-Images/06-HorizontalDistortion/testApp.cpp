#include "testApp.h"

ofImage image;		//Original image
ofImage image2;		//Modified image

//--------------------------------------------------------------
void testApp::setup(){
	image.loadImage( "../../../Images/sunflower.png" );	//Load image	
	image2.clone( image ); 				//Copy image to image2
}

//--------------------------------------------------------------
void testApp::update(){
	float time = ofGetElapsedTimef();

	//Build image2 using image
	for (int y=0; y<image.getHeight(); y++) {
		for (int x=0; x<image.getWidth(); x++) {
			//Use y and time for computing shifted x1
			float amp = sin( y * 0.03 );
			int x1 = x + sin( time * 2.0 ) * amp * 50.0;

			//Clamp x1 to range [0, image.width-1]
			x1 = ofClamp( x1, 0, image.getWidth() - 1 );

			//Set image2(x, y) equal to image(x1, y)
			ofColor color = image.getColor( x1, y );
			image2.setColor( x, y, color );
		}
	}
	image2.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );
	ofSetColor( 255, 255, 255 );
	image2.draw( 0, 0 );
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
