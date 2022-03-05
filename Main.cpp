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
	glfwMakeContextCurrent(window);
	Shader shaderObj("Shaders/shader.vs","Shaders/shader.fs");
	VAO vaoNode;
	vaoNodePtr=&vaoNode;
	vaoNodePtr->Bind();
	VBO vbo1(render.NodesPositions);
	EBO ebo1(render.NodePositionIndices);
	vaoNodePtr->LinkVBOpos(vbo1,0);
	vaoNodePtr->LinkVBOcolor(vbo1,1);
	vaoNodePtr->Unbind();
	vbo1.Unbind();
	ebo1.Unbind();

	VAO vaoPath;
	vaoPath.Bind();
	VBO vbo2(render.PathVertices);
	EBO ebo2(render.PathIndices);
	vaoPath.LinkVBOpos(vbo2,0);
	vaoPath.LinkVBOcolor(vbo2,1);
	vaoPath.Unbind();
	vbo2.Unbind();
	ebo2.Unbind();

	VAO vaoEdge;
	vaoEdgePtr=&vaoEdge;
	vaoEdge.Bind();
	VBO vbo3(render.NodesPositions);
	EBO ebo3(render.EdgeIndices);
	vaoEdge.LinkVBOpos(vbo3,0);
	vaoEdge.LinkVBOcolor(vbo3,1);
	vaoEdge.Unbind();
	vbo3.Unbind();
	ebo3.Unbind();
	VAO vaoSrcDest;
	vaoSrcDest.Bind();
	VBO vbo4(render.SrcDestVertices);
	EBO ebo4(render.SrcDestIndices);
	vaoSrcDest.LinkVBOpos(vbo4,0);
	vaoSrcDest.LinkVBOcolor(vbo4,1);
	vaoSrcDest.Unbind();
	vbo4.Unbind();
	ebo4.Unbind();
	while(!glfwWindowShouldClose(window)){
		glfwPollEvents();
		glfwSetKeyCallback(window,key_callback);	
		glClearColor(0.1f,0.1f,0.1f,0.5f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderObj.Activate();//activate shader
		vaoNodePtr->Bind();//bind nodes array attributes
		glPointSize(30);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_POINT_SMOOTH );
		shaderObj.DrawBuffer(GL_POINTS,render.NodePositionIndices.size());
		 glDisable(GL_POINT_SMOOTH);
  		 glBlendFunc(GL_NONE, GL_NONE);
    		glDisable(GL_BLEND);

		vaoEdgePtr->Bind();//bind edge array attributes
		shaderObj.DrawBuffer(GL_LINES,render.EdgeIndices.size());

		vaoSrcDest.Bind();//bind srcDest Node array attributes
		shaderObj.DrawBuffer(GL_LINES,render.SrcDestIndices.size());
		vaoPath.Bind();//bind path array attributes
		shaderObj.DrawBuffer(GL_POINT,render.PathIndices.size());
		glfwSwapBuffers(window);
	}
	vaoNode.Delete();
	vbo1.Delete();
	vbo2.Delete();
	vbo3.Delete();
	vbo4.Delete();
	vaoPath.Delete();
	vaoSrcDest.Delete();
	vaoEdge.Delete();
	shaderObj.Delete();
	glfwTerminate();
	return 0;
}
