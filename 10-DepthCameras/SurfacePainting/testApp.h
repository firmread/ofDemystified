#ifndef _TEST_APP
#define _TEST_APP

/*
This example demonstrates how to work with depth image from depth camera
using ofxOpenNI.

It is a painting application. 
You calibrate camera with projector image (or TV screen), 
and then move your hands near projection surface.
Camera tracks this and draws corresponding areas in the projector's picture.

----------------------------------------------------------------------
For playing with the project, you need a depth camera, containing both depth and color sensors.
If you have depth camera with just depth sensor, 
you need to change the project's code by yourself to calibrate it without color camera's image

----------------------------------------------------------------------
How to make the project:
This project is based on ImageAndDepth-Simple example of ofxOpenNI.
1. Install ofxOpenNI (read README file in addon's folder)
2. Build and run ImageAndDepth-Simple example to check the addon is properly installed
and depth camera works.
3. Replace src folder with source files of this example (SurfacePainting)
4. Clean, build, and run this example!

----------------------------------------------------------------------
How to work with this application:
1.	Enable the projector or TV, and send there the content of your screen

2.	Run the project. You will see color and depth images on the white screen. 
Position the camera so it see the whole surface image. 
Then look at the depth image. 
If depth image is filled with some solid color – all is ok. 
But if depth image has many black pixels, it means that the camera is too close 
or too far from the surface or surface material is too dark, transparent or reflecting. 
In this case try to move the camera until you find the better position.

3.	Use your mouse to mark four corners of the surface at the color image.  
It is assumed that corners ordered clock-wise starting from top left corner. 

4.	Go away from the surface and press Space key. 
Then application store current depth image as background depth image and switch to the drawing mode.

5.	Now it's time for you to enter. Go to the surface, and move the hands near 
it at distance from 30 to 150 mm. 
You will see how your hands draw colors on the surface, 
resulted in black and white abstract drawing.
----------------------------------------------------------------------

It's the example SurfacePainting from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 10 - Using Depth Cameras
*/

#include "ofxOpenNI.h"
#include "ofMain.h"

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

	ofxOpenNI openNIDevice;			//Depth camera

	int W, H;						//Screen size
	vector<ofPoint> corners; 		//Marked corners of the surface
	ofShortPixels backgroundDepth;	//Background depth image

	ofPixels outPixels;	//Pixels array holding current drawing
	ofImage outImage;	//Output image built from outPixels

	bool calibrating;	//Working mode selector – calibrate or draw
	ofPoint shift;		//Point used for drawing shifted color image
};

#endif
