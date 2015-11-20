#pragma once

/*
This is radial slit-scan effect inplementation.
Move the mouse - it will be center where portion of new frame is drawn. 
The other pixels are filled using the older frames, 
where frame "oldness" depends of the distance 
between mouse position and the pixel. 

It's the example 04-VideoSlitScan from the book 
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

	ofVideoPlayer video;		//Video player object

	deque<ofPixels> frames;		//Frames buffer
	int N;						//Frames buffer size

	//Pixels array for constructing output image
	ofPixels imagePixels;
	ofImage image;				//Output image

	//Main processing function which
	//computes the pixel color (x, y) using frames buffer
	ofColor getSlitPixelColor( int x, int y );	

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
