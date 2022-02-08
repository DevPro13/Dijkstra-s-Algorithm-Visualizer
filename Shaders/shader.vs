#version 330 core
layout(location=0) in vec3 aPos;
layout(location=1) in vec3 aColor;
layout(location=2) in vec2 aTexCoord;
out vec3 OutColor;
out vec2 TexCoord
//uniform float scale;//controls the scale of the vertices
void main()
	{	// Outputs the positions/coordinates of all vertices
		gl_Position=vec4(aPos.x,aPos.y,aPos.z,1.0);
	//gl_Position = vec4(aPos.x + aPos.x * scale, aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
		OutColor=aColor;
		TexCoord=aTexCoord;
 }
