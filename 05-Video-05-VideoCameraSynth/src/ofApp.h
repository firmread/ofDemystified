#pragma once

/*
This is a video synthesizer, combining live video 
from camera and prerecorded video.
It use colors of live video pixels for shifting pixels 
of the prerecorded video.

Before running the example, connect web camera to your PC.
(If you use laptop with built-in webcam, then most probably 
it will works by itself.)

It's the example 05-VideoCameraSynth from the book 
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

	ofVideoGrabber 	grabber;	//Video grabber

	ofVideoPlayer 	video;		//Prerecorded video

	ofImage image;	//Resulted synthesized image

	//Synthesize image from grabber and video frames
	void synthesizeImage();	

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
