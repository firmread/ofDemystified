#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//Pyramid's base vertices with indices 0, 1, 2
	mesh.addVertex( ofPoint( -200, -100, -50 ) );
	mesh.addVertex( ofPoint( 200, -100, -50 ) );
	mesh.addVertex( ofPoint( 0, 200, 0 ) );

	//Pyramid's top vertex with index 3
	mesh.addVertex( ofPoint( 0, 0, 50 ) );

	//Vertices with indices 3, 2, 0
	mesh.addTriangle( 3, 2, 0 );

	//Vertices with indices 3, 1, 2
	mesh.addTriangle( 3, 1, 2 ); 

	//Vertices with indices 3, 0, 1
	mesh.addTriangle( 3, 0, 1 );

	setNormals( mesh );			//Set normals to the surface
	//Note, setNormals is our function, 
	//which is declared 

	//Enabling light source
	light.enable();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableDepthTest();			//Enable z-buffering

	//Set a background
	ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );

	ofPushMatrix();					//Store the coordinate system

	//Move coordinate center to screen's center
	ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );

	//Rotate the coordinate system
	float time = ofGetElapsedTimef(); //Get time in seconds
	float angle = time * 30;		//Rotate angle
	ofRotate( angle, 0, 1, 1 ); 

	ofSetColor( 0, 128, 0 );		//Set a dark green color
	mesh.draw();					//Draw the mesh

	ofPopMatrix();					//Restore the coordinate system
}

//--------------------------------------------------------------
//Universal function which sets normals for the triangle mesh
void setNormals( ofMesh &mesh ){

	//The number of the vertices
	int nV = mesh.getNumVertices();
	
	//The number of the triangles
	int nT = mesh.getNumIndices() / 3;

	vector<ofPoint> norm( nV ); //Array for the normals

	//Scan all the triangles. For each triangle add its
	//normal to norm's vectors of triangle's vertices
	for (int t=0; t<nT; t++) {

		//Get indices of the triangle t
		int i1 = mesh.getIndex( 3 * t );
		int i2 = mesh.getIndex( 3 * t + 1 );
		int i3 = mesh.getIndex( 3 * t + 2 );
		
		//Get vertices of the triangle
		const ofPoint &v1 = mesh.getVertex( i1 );
		const ofPoint &v2 = mesh.getVertex( i2 );
		const ofPoint &v3 = mesh.getVertex( i3 );
		
		//Compute the triangle's normal
		ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
		
		//Accumulate it to norm array for i1, i2, i3
		norm[ i1 ] += dir;
		norm[ i2 ] += dir;
		norm[ i3 ] += dir;
	}

	//Normalize the normal's length
	for (int i=0; i<nV; i++) {
		norm[i].normalize();
	}

	//Set the normals to mesh
	mesh.clearNormals();
	mesh.addNormals( norm );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}