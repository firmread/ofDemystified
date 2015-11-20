#pragma once
/*
This example creates and draws an animated image of moving color waves.

It's the example 04-ColorWaves from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 4 - Images and Textures
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
