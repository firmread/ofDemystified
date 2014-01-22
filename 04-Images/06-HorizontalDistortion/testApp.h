#pragma once
/*
This example distorts the geometry of image by shifting 
its horizontal lines by sine wave, which also changes with time.

It's the example 06-HorizontalDistortion from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 4 - Images and Textures
Credits:
Image "sunflower.png" by ©iStockphoto.com/Andrew Johnson.
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
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
