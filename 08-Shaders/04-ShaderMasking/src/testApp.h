#pragma once

/*
This example demonstrates processing several images with fragment shader. 
It masks drawing image (sunflower) with some predefined mask (rotated triangle).

It's the example 04-ShaderMasking from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 8 - Using Shaders

Credits:
Image "sunflower.png" by ©iStockphoto.com/Andrew Johnson.
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofShader shader;	//Shader
	ofFbo fbo;			//First buffer for input image
	ofFbo fbo2;			//Second buffer for mask
	
	ofImage image;		//Sunflower image

	void keyPressed  (int key);
	void keyReleased (int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};

