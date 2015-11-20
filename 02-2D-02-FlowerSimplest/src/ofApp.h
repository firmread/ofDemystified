#pragma once

/*
This example draws a circle, line and two triangles forming a kind of flower.

It's the example 02-FlowerSimplest from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 2 - Drawing in 2D
*/ 

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

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
