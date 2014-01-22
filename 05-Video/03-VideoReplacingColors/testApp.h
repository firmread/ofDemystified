#pragma once

/*
This example replaces the colors of a video frame
using random-generated replacing table.

It's the example 03-VideoReplacingColors from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 5 - Working with Videos
Credits:
Video "handsTrees.mov" by Igor Sodazot.
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofVideoPlayer video;	//Declare video player object
	ofImage image;		//Declare image object
	int table[16];		//Declare table for color replacing

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
private:
};
