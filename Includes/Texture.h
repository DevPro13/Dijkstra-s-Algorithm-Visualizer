#ifndef TEXTURE_H
#define TEXTURE_H
#include<glad/glad.h>
#include<iostream>
#include"ShaderClass.h"
#include<stb/stb_image.h>
#define STB_IMAGE_IMPLEMENTATION

class Texture{
	public:
		GLuint ID;
		Texture();
		Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
		void Bind();
		void Unbind();
		void Delete();
		void texUnit(Shader&,const char*,GLuint);
};
#endif
