#pragma once
/*
This example modifies the colors of an image 
right after the image loading.

It's the example 05-ImageModify from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 4 - Images and Textures
Credits:
Image "sunflower.png" by ©iStockphoto.com/Andrew Johnson.
*/

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
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
