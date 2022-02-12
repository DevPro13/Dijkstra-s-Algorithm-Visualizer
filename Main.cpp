#include"Includes/opengl.h"
#include<iostream>
using namespace std;
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 1080

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
int main(){
	initializeGLFW();
	GLFWwindow*window=glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"Dijkstra Algorithm Visualizer",NULL,NULL);
	if(window==NULL){
		clog<<"Window is not created"<<endl;
		glfwTerminate();
		return -1;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
      	 glfwMakeContextCurrent(window);	

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
	GLfloat vertices[]={
		//vertices		//color			//texture coordinate
		1.0f,1.0f,0.0f,		1.0f,0.0f,0.0f,		1.0f,1.0f,
		-1.0f,1.0f,0.0f,	0.0f,1.0f,0.0f,		-1.0f,1.0f,
		-1.0f,-0.5f,0.0f,	0.0f,0.0f,1.0f,		-1.0f,-0.5f,
		1.0f,-0.5f,0.0f,	1.0f,0.5f,1.0f,		1.0f,-0.5f
	};
	GLuint indices[]={
		0,1,
		1,2,
		2,3,
		3,0
	};
	glfwMakeContextCurrent(window);
	Shader shaderObj("Shaders/shader.vs","Shader/shader.fs");
	VAO vao1;
	vao1.Bind();
	VBO vbo1(vertices,sizeof(vertices));
	EBO ebo1(indices,sizeof(indices));
	vao1.LinkVBOpos(vbo1,0);//for position
	vao1.LinkVBOpos(vbo1,1);//for color
	vao1.LinkVBOpos(vbo1,2);//for textre position
	vao1.Unbind();
	vbo1.Unbind();
	ebo1.Unbind();

	glClearColor(0.1f,0.1f,0.1f,0.5f);
	while(!glfwWindowShouldClose(window)){
		glfwPollEvents();
		glfwSetKeyCallback(window,key_callback);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderObj.Activate();//activate shader
		vao1.Bind();//bind vao
		glLineWidth(20);
		glDrawElements(GL_LINES,8,GL_UNSIGNED_INT,0);
		glfwSwapBuffers(window);
	}
	glfwTerminate();

	return 0;
}
