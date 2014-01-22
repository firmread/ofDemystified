#include "testApp.h"

//--------------------------------------------------------------
//----------------------  Params -------------------------------
//--------------------------------------------------------------
Params param;        //Definition of global variable

void Params::setup() {
	eCenter = ofPoint( ofGetWidth() / 2, ofGetHeight() / 2 );
	eRad = 100;
	velRad = 0;
	lifeTime = 2.0;

	rotate = 0;
	force = 1000;
	spinning = 1000;
	friction = 0.05;
}

//--------------------------------------------------------------
//----------------------  Particle  ----------------------------
//--------------------------------------------------------------
Particle::Particle() {
	live = false;
}

//--------------------------------------------------------------
ofPoint randomPointInCircle( float maxRad ){
	ofPoint pnt;
	float rad = ofRandom( 0, maxRad );
	float angle = ofRandom( 0, M_TWO_PI );
	pnt.x = cos( angle ) * rad;
	pnt.y = sin( angle ) * rad;
	return pnt;
}

//--------------------------------------------------------------
void Particle::setup() {
	pos = param.eCenter + randomPointInCircle( param.eRad );
	vel = randomPointInCircle( param.velRad );
	time = 0;
	lifeTime = param.lifeTime;
	live = true;
}

//--------------------------------------------------------------
void Particle::update( float dt ){
	if ( live ) {
		//Rotate vel
		vel.rotate( 0, 0, param.rotate * dt );

		ofPoint acc;         //Acceleration
		ofPoint delta = pos - param.eCenter;
		float len = delta.length();
		if ( ofInRange( len, 0, param.eRad ) ) {
			delta.normalize();

			//Attraction/repulsion force 
			acc += delta * param.force;

			//Spinning force
			acc.x += -delta.y * param.spinning;
			acc.y += delta.x * param.spinning;
		}
		vel += acc * dt;            //Euler method
		vel *= ( 1 - param.friction );  //Friction
		
		//Update pos
		pos += vel * dt;    //Euler method

		//Update time and check if particle should die
		time += dt;
		if ( time >= lifeTime ) {
			live = false;   //Particle is now considered as died
		}
	}
}

//--------------------------------------------------------------
void Particle::draw(){
	if ( live ) {
		//Compute size
		float size = ofMap( 
			fabs(time - lifeTime/2), 0, lifeTime/2, 3, 1 );

		//Compute color
		ofColor color = ofColor::red;
		float hue = ofMap( time, 0, lifeTime, 128, 255 );
		color.setHue( hue );
		ofSetColor( color );

		ofCircle( pos, size );  //Draw particle
	}
}

//--------------------------------------------------------------
//----------------------  testApp  -----------------------------
//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate( 60 );	//Set screen frame rate

	//Allocate drawing buffer
	int w = ofGetWidth();
	int h = ofGetHeight();
	fbo.allocate( w, h, GL_RGB32F_ARB );

	//Fill buffer with white color
	fbo.begin();
	ofBackground(255, 255, 255);
	fbo.end();

	//Set up parameters
	param.setup();		//Global parameters
	history = 0.9;
	bornRate = 1500;

	bornCount = 0;
	time0 = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void testApp::update(){
	//Compute dt
	float time = ofGetElapsedTimef();
	float dt = ofClamp( time - time0, 0, 0.1 );
	time0 = time;

	//Delete inactive particles
	int i=0;
	while (i < p.size()) {
		if ( !p[i].live ) {
			p.erase( p.begin() + i );
		}
		else {
			i++;
		}
	}

	//Born new particles
	bornCount += dt * bornRate;      //Update bornCount value
	if ( bornCount >= 1 ) {          //It's time to born particle(s)
		int bornN = int( bornCount );//How many born
		bornCount -= bornN;          //Correct bornCount value
		for (int i=0; i<bornN; i++) {
			Particle newP;
			newP.setup();            //Start a new particle
			p.push_back( newP );     //Add this particle to array
		}
	}

	//Update the particles
	for (int i=0; i<p.size(); i++) {
		p[i].update( dt );
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );  //Set white background

	//1. Drawing to buffer
	fbo.begin();

	//Draw semi-transparent white rectangle
	//to slightly clearing a buffer (depends on history value)

	ofEnableAlphaBlending();         //Enable transparency

	float alpha = (1-history) * 255;
	ofSetColor( 255, 255, 255, alpha );
	ofFill();
	ofRect( 0, 0, ofGetWidth(), ofGetHeight() );

	ofDisableAlphaBlending();        //Disable transparency

	//Draw the particles
	ofFill();
	for (int i=0; i<p.size(); i++) {
		p[i].draw();
	}

	fbo.end();

	//2. Draw buffer on the screen
	ofSetColor( 255, 255, 255 );
	fbo.draw( 0, 0 );
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