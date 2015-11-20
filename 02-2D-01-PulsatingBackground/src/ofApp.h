#pragma once

/*
This example dynamically changes background from black to white 
using sinewave.

It's the example 01-PulsatingBackground from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 2 - Drawing in 2D
*/ 

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofPoint pos0;		//Centre of suspension
	ofPoint pos;		//Ball's position
	ofPoint velocity;	//Ball's velocity

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
