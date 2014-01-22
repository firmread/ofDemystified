#pragma once

/*
This example demontrates how to work with image sequence.
It overlays images with alpha channel (wool cloud) 
over background-layer video (elephant).
Also it demontrates how to use Perlin noise for "random-like" moving wool cloud.

It's the example 06-VideoImageSequence from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 5 - Working with Videos
Credits:
Video "elephant.mov" and image sequence "woolCloudSeq" by Igor Sodazot.
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	//Video which will play as the background layer
	ofVideoPlayer 	backVideo;

	//Image sequence which will be overlayed on backVideo
	vector<ofTexture> seq;	

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
