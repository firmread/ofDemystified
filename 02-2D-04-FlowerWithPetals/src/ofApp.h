#pragma once

/*
This example draws a flower using control points, 
and also draws triangle petals using coordinate system transformation.

It's the example 02-2D/04-FlowerWithPetals from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 2 - Drawing in 2D
*/ 

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	//Declare control points
	ofPoint stem0, stem1, stem2, stem3, leftLeaf, rightLeaf;

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
