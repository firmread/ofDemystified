#pragma once

/*
This example draws pyramid's surface using ofMesh,
with enabled light in scene and normals set to mesh.
The pyramid is looks like smooth 3D object.

This example is a good starting point for drawing smooth surfaces.

(See the "most natural" pyramid - with sharp edges 
in 04-PyramidSharpEdges example.)

It's the example 03-PyramidLighting from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 7 - Drawing in 3D
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		ofMesh mesh;
		ofLight light;

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

