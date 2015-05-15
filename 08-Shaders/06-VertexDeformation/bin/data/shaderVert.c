#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform float phase = 0.0;			//Phase for "sin" function
uniform float distortAmount = 0.25; //Amount of distorsion

void main() {
	//Get original position of the vertex
	vec3 v = gl_Vertex.xyz;
	
	//Compute value of distortion for current vertex
	float distort = distortAmount * sin( phase + 0.015 * v.y );
	
	//Move the position
	v.x /= 1.0 + distort;
	v.y /= 1.0 + distort;
	v.z /= 1.0 + distort;

	//Set output vertex position
	vec4 posHomog = vec4( v, 1.0 );
	gl_Position = gl_ModelViewProjectionMatrix * posHomog;

	//Set output texture coordinate and color in a standard way
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_FrontColor = gl_Color;
}
