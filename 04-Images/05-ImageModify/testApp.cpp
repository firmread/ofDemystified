#include "testApp.h"
ofImage image;		//Declare image object

//--------------------------------------------------------------
void testApp::setup(){
	image.loadImage( "../../../Images/sunflower.png" );  //Load image

	//Modifying image

	//Getting pointer to pixel array of image
	unsigned char *data = image.getPixels();

	//Calculate number of pixel components
	int components = image.getPixels().getBitsPerPixel() / 8;

	//Modify pixel array
	for (int y=0; y<image.getHeight(); y++) {
		for (int x=0; x<image.getWidth(); x++) {

			//Read pixel (x,y) color components
			int index = components * (x + image.getWidth() * y);
			int red = data[ index ];
			int green = data[ index + 1 ];
			int blue = data[ index + 2 ];

			//Calculate periodical modulation
			float u = abs(sin( x * 0.1 ) * sin( y * 0.1 ) );

			//Set red component modulated by u
			data[ index ] = red * u;

			//Set green value as inverted original red
			data[ index + 1 ] = (255 - red);

			//Invert blue component
			data[ index + 2 ] = (255 - blue);

			//If there is alpha component or not, 
			//we don't touch it anyway
		}
	}
	//Calling image.update() to apply changes
	image.update();
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );
	ofSetColor( 255, 255, 255 );
	image.draw( 0, 0 );		//Draw image
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
