#pragma once

#include "ofMain.h"

/*
Example transcodes central horizontal of the image grabbed by webcamera to sound. 

It's the example 04-ImageToSound from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 6 - Working with Sounds

**********  WARNING  *********************** 
To avoid the hazard of damaging your ears, 
do not listen the project's output sound with headphones.
This project uses low-level audio output, so due 
possible errors in software it can suddenly 
generate clicks and very loud sounds.
********************************************
*/


class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

	//Function for generating audio
	void audioOut( float * input, int bufferSize, int nChannels );

	ofSoundStream soundStream;	//Object for sound output setup

	ofVideoGrabber grabber; //Video grabber

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
