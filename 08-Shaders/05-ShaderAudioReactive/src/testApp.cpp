#include "testApp.h"

const int N = 256;		//Number of bands in spectrum
float spectrum[ N ];	//Smoothed spectrum values

ofFloatImage spectrumImage;

//--------------------------------------------------------------
void testApp::setup(){

	ofSetLogLevel(OF_LOG_VERBOSE);
	
	//Load image file
	image.loadImage( "sunflower.png" );	

	//Load shader
	shader.load( "shaderVert.c", "shaderFrag.c" );
	
		
	fbo.allocate( ofGetWidth(), ofGetHeight() );
	fbo2.allocate( ofGetWidth(), ofGetHeight() );


	//Set up sound sample
	sound.loadSound( "surface.wav" );	
	sound.setLoop( true );
	sound.play();
	
	//Set spectrum values to 0
	for (int i=0; i<N; i++) {
		spectrum[i] = 0.0f;
	}
}

//--------------------------------------------------------------
void testApp::update(){
	//Update sound engine
	ofSoundUpdate();	
	
	//Get current spectrum with N bands
	float *val = ofSoundGetSpectrum( N ); 
	//We should not release memory of val, 
	//because it is managed by sound engine

	//Update our smoothed spectrum, 
	//by slowly decreasing its values and getting maximum with val
	//So we will have slowly falling peaks in spectrum
	for ( int i=0; i<N; i++ ) {
		spectrum[i] *= 0.95; //0.97;	//Slow decreasing
		spectrum[i] = max( spectrum[i], val[i] );
	}

	//Set spectrum to spectrumImage
	spectrumImage.setFromPixels( spectrum, N, 1, OF_IMAGE_GRAYSCALE );
}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableAlphaBlending();

	float time = ofGetElapsedTimef();
	float w = ofGetWidth();
	float h = ofGetHeight();

	fbo.begin();
	
	//Draw something on the screen

	//Set a gradient background from white to gray 
	//See "Sharp sphere example" in chapter "Creating in 3D with openFrameworks"
	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );

	ofSetColor( 255, 255, 255 );
	image.draw( 351, 221 );

	fbo.end();

	//Draw first image
	fbo2.begin();	
	ofBackground( 0, 0, 0 );
	float ang = time * 30;
	//ang = 0;

	ofPushMatrix();
	ofTranslate( w/2, h/2 );
	ofRotate( ang );
	ofFill();
	ofSetColor( 255, 255, 255 );
	ofTriangle( -200, -114, 200, -114, 0, 230 );
	ofPopMatrix();

	fbo2.end();

	//Enable shader
	shader.begin();
	
    //pass time value to shader
	shader.setUniform1f("time", time );
			
	//we also pass in the mouse position 
	//we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped. 
	//shader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY );
	shader.setUniformTexture( "texture1", fbo2.getTextureReference(), 1 ); //"1" means that it is texture 1

	shader.setUniformTexture( "texture2", spectrumImage.getTextureReference(), 2 ); //"2" means that it is texture 2

	//shader.setUniform1i( "N", N );
	shader.setUniform1fv( "specArray", spectrum, N );

	//Draw image through shader
	ofSetColor( 255, 255, 255 );
	fbo.draw( 0, 0 );

	//ofSetColor( 255, 255, 255, 128 );
	//fbo2.draw( 0, 0 );

	shader.end();

	//Draw spectrum
/*	ofFill();
	ofSetColor( 0, 255, 0 ); 
	for (int i=0; i<N; i++) {
		ofRect( w/2 + i * 7, h/2, 7, -spectrum[i] * 100 );
	}

	ofSetColor( 255, 255, 255 );
	spectrumImage.draw( w/2, 0, N*7, 50 );
	*/
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 

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

