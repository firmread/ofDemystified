#pragma once

#include "ofMain.h"

/*
This example records and plays short sound sample.
Press 1 for recording, and press 2 for playing.

It's the example 05-LoopSampler from the book 
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


class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

	//Function for receiving audio
	void audioReceived( float *input, int bufferSize, int nChannels );

	//Function for generating audio
	void audioOut( float *output, int bufferSize, int nChannels );

	//Object for sound output and input setup
	ofSoundStream soundStream;


	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
