#pragma once

/*
This example uses a fragment shader for distorting the geometry of image. 
Namely, it transforms the image by shifting its lines by sine wave, which also changes with time.
The example demonstrates how to pass float parameter to shader

It's the example 02-ShaderHorizDistortion from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 8 - Using Shaders

Credits:
Image "sunflower.png" by ©iStockphoto.com/Andrew Johnson.
*/

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofShader shader;	//Shader
	ofFbo fbo;			//Buffer for intermediate drawing
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

