#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect texture0;
uniform sampler2DRect texture1;	//Second texture

void main(){
	vec2 pos = gl_TexCoord[0].xy;
	vec4 color0 = texture2DRect(texture0, pos);
	vec4 color1 = texture2DRect(texture1, pos);
	//Compute resulted color
	vec4 color;
	color.rgb = color0.rgb;
	color.a = color1.r;

	//Output of the shader
	gl_FragColor = color;
}
