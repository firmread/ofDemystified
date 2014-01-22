#pragma once

/*
This example combines music and images for obtaining audio-reactive 
visualization using a shader.

It's the example 05-ShaderAudioReactive from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 8 - Using Shaders

Credits:
Music track "surface.wav" by Ilya Orange (soundcloud.com/ilyaorange)
Image "sunflower.png" by ©iStockphoto.com/Andrew Johnson.
*/

#include "ofMain.h"

class testApp : public ofBaseApp{
	
	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		
		ofFbo fbo;		//buffer for drawing screen
		ofFbo fbo2;		//second buffer for drawing screen

		ofImage image;		//Sunflower image 
		ofShader shader;	//Shader

		ofSoundPlayer sound;	//Sound sample
};

