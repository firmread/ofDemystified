#pragma once

/*
This example demonstrates using vertex shader for deforming 3D objects.
It draws cloud of triangles and apply vertex shader to deform it.
The mouse position controls the following parameters:
x - amount of deformation, y - speed of deformation pulsation. 

It's the example 06-VertexDeformation from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 8 - Using Shaders
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofShader shader;	//Shader

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
