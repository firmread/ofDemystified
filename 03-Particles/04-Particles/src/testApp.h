#pragma once

/*
This example demonstrates the particle system with GUI.
GUI consists of sliders for adjusting all control parameters
of the particle system.
Keys: 
    Enter - hide/show GUI
	Space - save screenshot (file name selected randomly as screenNNN.png)
	1,2,...,9 - load preset
	Shift+1,2,...,9 - save preset
Presets stores as text files presetN.txt in "bin/data" folder of the project.

Copy "data" folder included in this example to "data" folder of your project
to play with our presets.

It's the example 04-Particles from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 3 - Building a Simple Particle System
*/  

#include "ofMain.h"

//Particle class
class Particle {
public:
	Particle();                //Class constructor
	void setup();              //Start particle
	void update( float dt );   //Recalculate physics
	void draw();               //Draw particle

	ofPoint pos;               //Position
	ofPoint vel;               //Velocity
	float time;                //Time of living
	float lifeTime;            //Allowed lifetime
	bool live;                 //Is particle live
};

//Control parameters class
class Params {
public:
	void setup();
	ofPoint eCenter;    //Emitter center
	float eRad;         //Emitter radius
	float velRad;       //Initial velocity limit
	float lifeTime;     //Lifetime in seconds

	float rotate;   //Direction rotation speed in angles per second

	float force;       //Attraction/repulsion force inside emitter
	float spinning;    //Spinning force inside emitter
	float friction;    //Friction, in the range [0, 1]
};

extern Params param; //Declaration of a global variable


//------------ GUI --------------
//Slider class
class Slider {
public:
	string title;		//Title
	ofRectangle rect;	//Rectangle for drawing
	float *value;       //Pointer to value which the slider changes
	float minV, maxV;   //Minimum and maximum values
};

//Interface class, which manages sliders
class Interface {
public:
	void setup();
	void addSlider( string title, float *value, float minV, float maxV );
	void draw();

	void save( int index );		//Save preset
	void load( int index );		//Load preset

	void mousePressed( int x, int y );
	void mouseDragged( int x, int y );
	void mouseReleased (int x, int y );

	vector<Slider> slider;	//Array of sliders
	int selected;			//Index of selected slider
};
//-------------------------------

//openFrameworks' class
class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	vector<Particle> p;	  //Particles
	ofFbo fbo;            //Off-screen buffer for trails

	float history;        //Control parameter for trails
	float time0;          //Time value for computing dt

	float bornRate;       //Particles born rate per second
	float bornCount;      //Integrated number of particles to born

	//GUI
	Interface interf;
	bool drawInterface;
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
