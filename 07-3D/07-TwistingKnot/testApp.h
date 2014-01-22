#pragma once

/*
This example creates tube-like surface, which is formed from a number of deformed circles. 
At each update() call, we will generate one circle 
and connect it with previous circle by adding triangles to the surface. 
At each step circle will slowly move, rotate and deform in a space. 
As result, we will see the growing and twisting 3D-knot.

It's the example 07-TwistingKnot from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 7 - Drawing in 3D
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofMesh mesh;		//Mesh
	ofLight light;		//Light
	void addRandomCircle( ofMesh &mesh ); //Main function which
	//moves circle and adds triangles to the object


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

//Universal function which sets normals
//for the triangle mesh
void setNormals( ofMesh &mesh );

