#pragma once

/*
This is example of searching bright objects in video, which uses ofxOpenCv addon,
namely, class ofxCvContourFinder.

At first, it decimates input frame to processing speed-up.
Then it smoothes image for improving searching quality.
The first frame of the video is considered as background.
It is subtracted from all input frames, 
so only bright objects remain in the resulted image.
Their contours are extracted using ofxCvContourFinder class.

Running the project, you will see the following images
[Original decimated image           ]	[Difference image-background ]
[Thresholded difference and contours]	[Original decimated image and centers of objects]

Press key '2' to see how some additional rendering effect based on found objects,
which is overlayed on the original video.
Press key '1' to return the original view.

--------------------------------------
How to make openFrameworks project:
- Use Project generator for creating an empty project with linked ofxOpenCv addon.
- Copy this sources to src folder of the project.
- Copy movie fruits.mov into bin/data folder of the project.
--------------------------------------

It's the example 04-SearchingObjects from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 9 - Computer Vision with OpenCV
*/

#include "ofMain.h"
#include "ofxOpenCv.h"

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	ofVideoPlayer video;		//Declare the video player object

	ofxCvColorImage image;	
	ofxCvColorImage imageDecimated;	

	ofxCvGrayscaleImage grayImage;
	ofxCvGrayscaleImage blurred;
	ofxCvGrayscaleImage background;
	ofxCvGrayscaleImage diff;
	ofxCvGrayscaleImage mask;

	ofxCvContourFinder 	contourFinder;

	vector<ofPoint> obj;	//object's centers

	int drawMode;	//Drawing mode, 
					//0 - image processing
					//1 - additional rendering
	void generateImg( int w, int h );	//Additional rendering
	ofImage img;						//Rendered image

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		

};

