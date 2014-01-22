//Specify compiler to use GLSL version 1.2
//Enable working with textures of any dimensions
//Declare texture texture0, which is linked when you use fbo.bind(), or any other texture.bind().

//#version 430 compatibility
#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect texture0;     //it can be named in any way, GLSL just links it

uniform sampler2DRect texture1;		//second image
uniform sampler2DRect texture2;		//spectrum

#define N (256)
uniform float specArray[N];

//uniform float time;             //Uniform value "time"

//blurring
void main(){
    vec2 pos = gl_TexCoord[0].st;     
	
	
    vec4 color0 = texture2DRect(texture0, pos);
	vec4 color1 =  texture2DRect(texture1, pos);	//colors converted to 0..1


	vec2 center = vec2(1024.0, 768.0) / 2.0;
	float dist = distance( center, pos );	//built-in function for distance 

	//Aliasing
	//int index = int( dist / 7.0 );
	//index = clamp( index, 0, N-1 );
	//float spectrValue = specArray[ index ];

	//Antialiasing
	vec2 spectrumPos = vec2( dist / 7.0, 0.5 );
	vec4 color2 =  texture2DRect(texture2, spectrumPos);	//spectrum values
	float spectrValue = color2.r;		//get spectrum value, normally in [0..1] 


	vec2 delta = pos - center;
	delta *= 1-2*spectrValue;
	vec2 posS = center + delta;

	//Audio responsible
	color0 = texture2DRect(texture0, posS);
	color1 = texture2DRect(texture1, posS);


	vec4 color;

	//Case: Example
	color = min( color0, color1 );	

	//Case: Show spectrum
	//color = vec4( 1.0-color2.rgb, 1.0 );		



	//color = color0;		//Test image passing
	//color = color1;


	//if ( color2.r > 0.3 ) { color = color0; }
	//else { color = color1; }
	//color = mix( color0, color2, color2.r );
	
	


	//int x = int(pos.x);	//we can not convert float to int explicitly, so need use implicit conversion
	//if ( x % 2 == 0 ) {
	//	color = color1;
	//}

	//Output of shader
	gl_FragColor = color;
}



/*
void main(){
    //Shader which sets blue color component of screen to zero
	//Such shader can be considered as template for other post-processing shaders

	//Getting coordinates of current pixel in texture
    vec2 pos = gl_TexCoord[0].st;     //pos.x, pos.y - 

	float angle = time * 2;

	float amp = sin( pos.y * 0.03 );
	//float amp = sin( pos.x * 0.03 );		//Playing with distortion function
	
	pos.x += 50*sin( angle ) * amp;

	//Getting pixel color from texture tex0 in position pos
    vec4 color = texture2DRect(tex0, pos);

	//Changing color (invert red, green, blue components and do not change alpha)
	//color.r = 1.0 - color.r;
	//color.g = 1.0 - color.g;
	//color.b = 1.0 - color.b;
	//color.a - not changing alpha component

	//Output of shader
	gl_FragColor = color;




    //vec4 color = texture2DRect(tex0, pos) * gl_Color;

	//gl_FragColor = texture2D(tex0, gl_TexCoord[0].st) * gl_Color;

//	gl_FragColor.g = 0;

    //gl_FragCoord gives us the x and y of the current pixel its drawing
    //
    
    
    //vec3 src = texture2DRect(tex0, pos).rgb;
    //float mask = texture2DRect(maskTex, pos).r;
    
    //gl_FragColor = vec4( src , mask);

	
    
    //https://github.com/mattdesl/lwjgl-basics/wiki/GLSL-Versions

    
    
    
    
	//this is the fragment shader
	//this is where the pixel level drawing happens
	//gl_FragCoord gives us the x and y of the current pixel its drawing
	
	//we grab the x and y and store them in an int
	//float xVal = gl_FragCoord.x;
	//float yVal = gl_FragCoord.y;
	
	//we use the mod function to only draw pixels if they are every 2 in x or every 4 in y
	//if( mod(xVal, 2.0) == 0.5 && mod(yVal, 4.0) == 0.5 ){
	//	gl_FragColor = gl_Color;    
    //}else{
	//	gl_FragColor.a = 0.0;
	//}
	
	
	//gl_FragColor = gl_Color; 
	
}

*/