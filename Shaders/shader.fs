#version 330 core
in vec3 OutColor;
in vec2 TexCoord;
out vec4 FragColor;
uniform sampler2D ourTexture
void main()
	{
        	FragColor=vec4(OutColor,1.0f);
        	//FragColor=texture(ourTexture,TexCoord)*vec4(OutColor,1.0f);
 }

