#pragma once

/*
This example draws spiral-like curves using simple drawing algorithm.
The example demonstrates how to use ofFBO drawing buffer.
Also it demonstrates screen grabbing: press Space key 
and the contents of the screen will be saved in file data/screen.png 

It's the example 02-2D/06-Spirals from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 2 - Drawing in 2D
*/ 

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	double a, b;			//Angle and its increment   (Stable curves)
	//float a, b;			//Angle and its increment	(Unstable curves)

	ofPoint pos, lastPos;	//Current and last drawing position
	ofColor color;			//Drawing color
	int colorStep;			//Counter for color changing
	ofFbo fbo;				//Drawing buffer

	void draw1();			//Draw one line segment

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
