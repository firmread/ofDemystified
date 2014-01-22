#pragma once

/*
This example draws moving pendulum in 2D, consisting of a ball dangled on a rubber segment.

It's the example 01-Pendulum from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 1 - openFrameworks Basics
*/ 

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofPoint pos0;			//Center of suspension
	ofPoint pos;			//Ball's position
	ofPoint velocity;		//Ball's velocity

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
