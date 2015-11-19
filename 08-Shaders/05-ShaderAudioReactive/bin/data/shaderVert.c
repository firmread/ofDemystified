#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

//uniform float timeValX = 1.0;
//uniform float timeValY = 1.0;
//uniform vec2 mouse;



void main()
{
	gl_FrontColor =  gl_Color;
	gl_TexCoord[0] = gl_MultiTexCoord0;
//	gl_Position = gl_Vertex;
	
	gl_Position = ftransform();	
}

/*
void main(){
	
	gl_TexCoord[0] = gl_MultiTexCoord0;
	
	//get our current vertex position so we can modify it
	vec4 pos = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
	
	//generate some noise values based on vertex position and the time value which comes in from our OF app
	float noiseAmntX = noise( vec2(-timeValX + pos.x / 1000.0f, 100.0f), 20.0 );
	float noiseAmntY = noise( vec2(timeValY + pos.y / 1000.0f, pos.x / 2000.0f), 20.0 );

	//generate noise for our blue pixel value
	float noiseB = noise( vec2(timeValY * 0.25, pos.y / 2000.0f), 20.0 );

	//lets also figure out the distance between the mouse and the vertex and apply a repelling force away from the mouse
	vec2 d = vec2(pos.x, pos.y) - mouse;
	float len =  sqrt(d.x*d.x + d.y*d.y);
	if( len < 300 && len > 0  ){
		
		//lets get the distance into 0-1 ranges
		float pct = len / 300.0; 
		
		//this turns our linear 0-1 value into a curved 0-1 value
		pct *= pct;

		//flip it so the closer we are the greater the repulsion
		pct = 1.0 - pct;
		
		//normalize our repulsion vector
		d /= len;
		
		//apply the repulsion to our position
		pos.x += d.x * pct * 90.0f;
		pos.y += d.y * pct * 90.0f;
	}

	//modify our position with the smooth noise
	pos.x += noiseAmntX * 20.0;
	pos.y += noiseAmntY * 10.0;
	
	//finally set the pos to be that actual position rendered
	gl_Position = pos;

	//modify our color
	vec4 col = gl_Color;
	col.b += noiseB;
	
	gl_FrontColor =  col;	
	
}*/
