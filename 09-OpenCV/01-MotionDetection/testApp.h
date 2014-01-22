#pragma once

/*
This is motion detection example, which uses ofxOpenCv addon.
It calculates of absolute differences between successive frames of video, 
accumulates them in the buffer, and finally computes motion areas
using thresholding.
Images on the screen:
[Original video         ]   [Difference image]
[Accumulated differences]	[Motion areas    ]

--------------------------------------
How to make openFrameworks project:
- Use Project generator for creating an empty project with linked ofxOpenCv addon.
- Copy this sources to src folder of the project.
- Copy movie handsTrees.mov into bin/data folder of the project.
--------------------------------------

It's the example 01-MotionDetection from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 9 - Computer Vision with OpenCV
*/

#include "ofMain.h"
#include "ofxOpenCv.h"

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	ofVideoPlayer video;		//Declare the video player object

	ofxCvColorImage image;		//The current video frame

	//The current and the previous video frames as grayscale images
	ofxCvGrayscaleImage grayImage, grayImagePrev;

	ofxCvGrayscaleImage diff;		//Absolute difference of the frames
	ofxCvFloatImage diffFloat;		//Amplified difference images
	ofxCvFloatImage bufferFloat;	//Buffer image

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		
};

