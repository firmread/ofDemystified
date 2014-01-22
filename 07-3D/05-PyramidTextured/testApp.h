#pragma once

/*
This example draws textured pyramid's surface using ofMesh,
with enabled light in scene and normals set to mesh.
Also each triangle is drawn as separate primitive, 
so pyramid has sharp edges.

It's the example 05-PyramidTextured from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 7 - Drawing in 3D

Credits:
Image "sunflower.png" by ©iStockphoto.com/Andrew Johnson.
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		ofMesh mesh;
		ofImage image;

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

