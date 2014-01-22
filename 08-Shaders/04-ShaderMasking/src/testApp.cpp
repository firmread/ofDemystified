#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	shader.load( "shaderVert.c", "shaderFrag.c" );

	fbo.allocate( ofGetWidth(), ofGetHeight() );
	fbo2.allocate( ofGetWidth(), ofGetHeight() );

	image.loadImage( "sunflower.png" );	
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	float time = ofGetElapsedTimef();

	//1. Drawing input image (sunflower) into fbo buffer
	fbo.begin();		
	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
	ofSetColor( 255, 255, 255 );
	image.draw( 351, 221 );
	fbo.end();			

	//2. Drawing mask (rotated triangle) into fbo2 buffer
	fbo2.begin();	
	ofBackground( 0, 0, 0 );
	float ang = time * 30;

	ofPushMatrix();
	ofTranslate( 512, 384 );
	ofRotate( ang );
	ofFill();
	ofSetColor( 255, 255, 255 );
	ofTriangle( -200, -114, 200, -114, 0, 230 );
	ofPopMatrix();
	fbo2.end();

	//3. Drawing to screen through the shader
	ofEnableAlphaBlending();		
	//NOTE: It is important to enable alpha blending for correct shader's working,
	//because shader performs masking by setting alpha-value of output color

	shader.begin();		

	shader.setUniform1f( "time", time );	//Pass float parameter "time" to shader
	//Pass mask to shader (fbo2)
	shader.setUniformTexture( "texture1", fbo2.getTextureReference(), 1 ); 
	//Last parameter 1 is OpenGL texture identifier 

	//Draw fbo image
	ofSetColor( 255, 255, 255 );
	fbo.draw( 0, 0 );

	shader.end();		
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

