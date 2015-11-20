#pragma once

#include "ofMain.h"

/*
This example synthesizes PWM-sound. 
The mouse position change parameters: x - frequency, y - PWM-value.

It's the example 03-PWMSynth from the book 
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

	//User-changing parameters
	float userFreq;				//Frequency
	float userPwm;				//PWM-value

	//Parameters, used during synthesis
	float freq;					//Current frequency
	float pwm;					//Current PWM-value
	float phase;				//Phase of the wave

	//Buffer for rendering last generated audio buffer
	vector<float> buf;


	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
