#pragma once

/*
This is example of video morphing, which uses ofxOpenCv addon and OpenCV.
The example demonstrates how to use native OpenCV functions with openFrameworks
(it calls cv::calcOpticalFlowFarneback for optical flow computing).

It compute optical flow between two images, 
and use it for morphing some other image.
You can choose what image to morph: 
- first input image (key '1') 
- checkerboard image (key '2').
The x-position of mouse sets morphing value,
so move it from left to right and see the morphing.

Running the project, you will see the following images
[Image1 and optical flow ]	[Image2]
[Morphed image           ]	

--------------------------------------
How to make openFrameworks project:
- Use Project generator for creating an empty project with linked ofxOpenCv addon.
- Copy this sources to src folder of the project.
- Copy images fruits.mov into bin/data folder of the project.

--------------- ATTENTION --------------
Before running the project, fix small ofxOpenCv bug.

Currently the operation image = &iplImage raises error, 
if image is not allocated. 
To fix it, open addon's file addons/ofxOpenCv/src/ofxCvImage.cpp 
and find the following function definition:
void ofxCvImage::operator = ( const IplImage* mom )
In this function body, replace line 
	if( mom->nChannels == cvImage->nChannels && mom->depth == cvImage->depth ){
with the following line:
	if( !bAllocated || ( mom->nChannels == cvImage->nChannels && mom->depth == cvImage->depth ) ){

(Note, without this fix, the following example lines flowX = &iplX; and flowY = &iplY; 
can raise runtime error)

--------------------------------------
It's the example 05-VideoMorphing from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 9 - Computer Vision with OpenCV

Credits:
Images "hands1.png" and "hands2.png" by Igor Sodazot.
*/

#include "ofMain.h"
#include "ofxOpenCv.h"
using namespace cv;

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();


	ofxCvColorImage color1, color2;		//First and second original images
	ofxCvGrayscaleImage gray1, gray2;	//Decimated grayscaled images
	ofxCvFloatImage flowX, flowY;		//Resulted optical flow in x and y axes

	ofxCvColorImage colorTest;			//Input image "checkerboard" for morphing

	int w, h;							//Decimated size of input images

	ofxCvGrayscaleImage planeX, planeY;

	ofxCvFloatImage idX, idY;	//idX(x,y) = x, idY(x,y) = y
	ofxCvFloatImage mapX, mapY;
	ofxCvFloatImage bigMapX, bigMapY;

	ofxCvFloatImage fx, fy;
	ofxCvFloatImage weight;

	float morphValue;	//[0, 1]
	ofxCvColorImage morph;	//Resulted morphed image
	int morphImageIndex;		//What to morph: 1 - first input image, 2 - checkerboard image

	//Inverting the mapping (mapX, mapY), with antialiasing.
	void inverseMapping( ofxCvFloatImage &mapX, ofxCvFloatImage &mapY );
	
	//Making image morphing
	void updateMorph( float morphValue, int morphImageIndex );

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

