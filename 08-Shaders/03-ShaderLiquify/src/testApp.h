#pragma once

/*
This example uses a fragment which shifts each pixel using Perlin noise. 
The resulted effect will be liquid-like waving of the input image.

It's the example 03-ShaderLiquify from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 8 - Using Shaders

Credits:
- Shader's Perlin noise implementation float cnoise(vec3 P) 
	is taken from src/classicnoise3D.glsl file
	from webgl-noise library by Ashima Arts and Stefan Gustavson, 
	https://github.com/ashima/webgl-noise 

- Image "sunflower.png" by ©iStockphoto.com/Andrew Johnson.
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
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

