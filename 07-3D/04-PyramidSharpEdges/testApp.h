#pragma once

/*
This example draws pyramid's surface using ofMesh,
with enabled light in scene and normals set to mesh.
Also each triangle is drawn as separate primitive, 
so pyramid has sharp edges.
This is most natural view of pyramid among examples.

This example is a good start point for drawing sharp 3D objects.

It's the example 04-PyramidSharpEdges from the book 
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

