#ifndef INCLUDES_H
#define INCLUDES_H
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include"ShaderClass.h"
#include"VAO.h"
#include"EBO.h"
#include"VBO.h"
#include"Texture.h"
void initializeGLFW(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,4);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	gladLoadGL();
}
#endif
