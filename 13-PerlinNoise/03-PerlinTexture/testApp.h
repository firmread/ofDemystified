#pragma once

/*
This example draws static or evolving texture 
using 2D or 3D Perlin noise function.

It's the example 03-PerlinTexture from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Appendix B - Perlin Noise
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
