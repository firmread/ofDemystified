#pragma once

/*
This example plays video on the screen.

It's the example 01-VideoPlayback from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 5 - Working with Videos
Credits:
Video "handsTrees.mov" by Igor Sodazot.
*/

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofVideoPlayer video;	//Declare the video player object

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
