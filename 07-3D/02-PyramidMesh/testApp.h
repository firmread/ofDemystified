#pragma once

/*
This example draws pyramid's surface using ofMesh.
The pyramid is colored with uniform dark green color,
so look like 2D polygon.
(See how to enable lighting and normals for adding more 3D look 
in 03-PyramidMeshLighting example.)

It's the example 02-PyramidMesh from the book 
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

