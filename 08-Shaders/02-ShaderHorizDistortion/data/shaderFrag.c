#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect texture0;

uniform float time; //Parameter which we will pass from OF

void main(){
	//Getting the coordinates of the current pixel in texture
	vec2 pos = gl_TexCoord[0].st;

	//Changing pos by sinewave
	float amp = sin( pos.y * 0.03 );
	pos.x += sin( time * 2.0 ) * amp * 50.0; //Shifting x-coordinate

	//Getting pixel color from texture tex0 in position pos
	vec4 color = texture2DRect(texture0, pos);
	//Output of shader
	gl_FragColor = color;	
}
