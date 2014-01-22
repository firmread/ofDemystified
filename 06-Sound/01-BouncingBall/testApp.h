#pragma once

#include "ofMain.h"

/*
This example shows a bouncing ball. When the ball bounced, a sound sample plays. 
The tone of the sample depends on ball's position.

It's the example 01-BouncingBall from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 6 - Working with Sounds
Credits:
Sample "bounce.wav" by Igor Sodazot.
*/

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

	ofSoundPlayer sound;		//Sound sample
	bool updateBall();			//Move ball function

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
