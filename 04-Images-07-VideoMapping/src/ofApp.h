#pragma once
/*
This example warpes a given texture to four specified corners.
Press keys '1', '2', '3', '4' for selecting a corner, and cursor keys for moving the corner.

It's the example 07-VideoMapping from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 4 - Images and Textures
Credits:
Image "sunflower.png" by ©iStockphoto.com/Andrew Johnson.
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
