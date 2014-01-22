#pragma once

/*
This example demonstrates sending images via network using TCP protocol.
Note, it uses webcamera as source of images.
Run it together with networkImageReceiver.

It's the example 11-Networking/networkImageSender from the book 
"Mastering openFrameworks: Creative Coding Demystified",
Chapter 11 - Networking

-------------------------------
How to create the openFrameworks project using these source files:

1. This project uses ofxNetwork addon, so make new project using Project Generator and check there ofxNetwork addon, 
or copy openFrameworks' example examples/addons/networkTcpClientExample 
to your projects folder and rename it in networkImageReceiver.

2. Copy all source files of this example to the src folder of your project, replacing existing one.

3. Open the project in your development environment and 
add pbNetwork.h and pbNetwork.cpp files to the project.

4. Also, in openFrameworks 0.8.0, you need to add two lines in the ofxNetwork addon:

	* In file addons/ofxNetwork/src/ofxTCPServer.h add 
	the following line to class ofxTCPServer, in its public declarations section 
	(for example, in line before "private:" keyword):

	ofxTCPManager &TCPServerRef() { return TCPServer; }

	* In file addons/ofxNetwork/src/ofxTCPClient.h add 
	the following line to class ofxTCPClient, in its public declarations section 
	(for example, in line before "private:" keyword):

	ofxTCPManager	&TCPClientRef() { return TCPClient; }

5. Now clean, compile and run the project.

*/

#include "ofMain.h"
#include "pbNetwork.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	int w, h;						//Width and height of image
	int size;						//Size of image data in bytes

	ofVideoGrabber 	grabber;		//Video grabber

	pbNetworkSenderSync _sender;	//Network sender
	int _frameId;					//id of sent frame

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

};
