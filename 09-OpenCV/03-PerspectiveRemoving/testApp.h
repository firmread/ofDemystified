#pragma once

/*
This is perspective distortion removing example, which uses ofxOpenCv addon.
It restores geometry of the flat rectangle image distorted by perspective effect.

To achieve this, we specify four corner points of the image inside input image:
  A----B
 /      \
D--------C

--------------------------------------
How to make openFrameworks project:
- Use Project generator for creating an empty project with linked ofxOpenCv addon.
- Copy this sources to src folder of the project.
- Copy copy image table.png into bin/data folder of the project.
--------------------------------------

It's the example 03-PerspectiveRemoving from the book 
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

	ofxCvColorImage image;	
	ofxCvColorImage image2;

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

