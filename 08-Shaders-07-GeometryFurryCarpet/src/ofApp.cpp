#include "ofApp.h"


ofImage image;

//--------------------------------------------------------------
void ofApp::setup(){

	//Enable detailed logging of openFrameworks messages in console
	ofSetLogLevel( OF_LOG_VERBOSE );

	//We must to specify geometry shader parameters before loading shader
	shader.setGeometryInputType( GL_LINES );
	shader.setGeometryOutputType( GL_LINE_STRIP );
	shader.setGeometryOutputCount( 128 );	//Maximal possible number of output vertices

	//Load shader
	shader.load( "shaderVert.c", "shaderFrag.c", "shaderGeom.c" );

	//printf("Maximum number of output vertices support is: %i\n", shader.getGeometryMaxOutputCount());

	fbo.allocate( ofGetWidth(), ofGetHeight() );
	image.loadImage( "sunflower-transp.png" );
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	float w = ofGetWidth();
	float h = ofGetHeight();

	//1. Drawing image to fbo
	//Hint: here we can draw any (animated) image!
	fbo.begin();
	ofBackground( 0, 0, 0, 0 );
	ofSetColor( 255, 255, 255 );
	float w1 = image.getWidth() * 2;
	float h1 = image.getHeight() * 2;
	image.draw( w/2-w1/2, h/2-h1/2, w1, h1 );
	fbo.end();

	//Reading contents of rendered fbo.
	//Below we will use it for line drawing 
	ofPixels pixels;
	fbo.readToPixels(pixels);

	//2. Drawing to screen
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();

	//Enable shader
	shader.begin();

	//Set shader's parameters
	float time = ofGetElapsedTimef();
	shader.setUniform1f( "time", time );
	shader.setUniformTexture( "texture", fbo.getTextureReference(), 1 );	

	//Draw lines (through vertex->geometry->fragment shaders)
	ofSetColor( 255, 255, 255 );
	int stepx = 10;
	int stepy = 10;
	float len = 20;
	//Scan fbo pixels colors and search for not-transparent pixels 
	for (int y=0; y<h; y+=stepy) {
		for (int x=0; x<w; x+=stepx) {
			if ( pixels.getColor( x, y ).a > 0 ) {
				//Draw line
				ofLine( x, y, x, y - len );		
			}
		}
	}

	//Hint: for better performance, we can use ofMesh and GL_LINE_STRIP in shader , 
	//but in this example we use lines for simplicity

	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
