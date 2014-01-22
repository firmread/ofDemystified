#pragma once

/*
This example demonstrates using geometry shader.
Namely, it implements shader which replace each passed line with a bunch of lines, 
such that these vertices positions will be distorted using Perlin noise. 
We obtain a “furry” collection of lines. 
Additionally, we set the color of each generated line as average color 
of the some image along this line. 
Finally we will obtain a colored 2D “furry carpet” with picture resembling the original image.

It's the example 07-GeometryFurryCarpet from the book 
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
	ofFbo fbo;

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
