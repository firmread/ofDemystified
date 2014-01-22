#pragma once

/*
This is example of image filtering, which uses ofxOpenCv addon.
It thresholds original image,
and also smooths and thresolds original image.
You can see that smooth+threshold gives binary image with smooth boundaries,
which is easies for further analyzing.

Images on the screen:
[Original image]	[Thresholded original image]
[Smoothed image]	[Thresholded smoothed image]

--------------------------------------
How to make openFrameworks project:
- Use Project generator for creating an empty project with linked ofxOpenCv addon.
- Copy this sources to src folder of the project.
- Copy copy image sunflower.png into bin/data folder of the project.
--------------------------------------

It's the example 02-ImageFiltering from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 9 - Computer Vision with OpenCV

Credits:
Image "sunflower.png" by ©iStockphoto.com/Andrew Johnson.
*/

#include "ofMain.h"
#include "ofxOpenCv.h"


class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	ofxCvColorImage image;			//Original image
	ofxCvGrayscaleImage grayImage;	//Grayscaled original image
	ofxCvGrayscaleImage filtered;	//Image used for filtering

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

