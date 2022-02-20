#ifndef INCLUDES_H
#define INCLUDES_H
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include"Node.h"
#include"ShaderClass.h"
#include"VAO.h"
#include"EBO.h"
#include"VBO.h"
//#include"Render.h"
#include"graph.hpp"
NodeTree newNodeLeaf;
Queue Q;
Edge edge;
Graph graph;
void initializeGLFW(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,4);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	gladLoadGL();
}
void mouse_button_callback_forNodeCreate(GLFWwindow* window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {        double xpos, ypos;
       //getting cursor position
        glfwGetCursorPos(window, &xpos, &ypos);
	 newNodeLeaf.createNode(Q,xpos,ypos);//create node at that position
	std::cout << "Node created at Position  (" << xpos << "," << ypos <<").\n";
    }
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(key==GLFW_KEY_1&& action == GLFW_PRESS){//press 1 to add nodes:
	    glfwSetMouseButtonCallback(window,mouse_button_callback_forNodeCreate);
    }
    
		else if(key==GLFW_KEY_2&& action == GLFW_PRESS){//to connect edges
				edge.JoinNodesRandom(Q,newNodeLeaf.totalNodesCreated());//join nodes randomly using combination
				graph.CreateGraph(edge,Q.newNodeLeaf.totalNodesCreated());//create graph
				}
		else if(key==GLFW_KEY_3&& action == GLFW_PRESS){//to select src and destination
						int srcID=newNodeLeaf.selectRandSrcDest();
						int destID=newNodeLeaf.selectRandSrcDest();
						while(srcID==destID)destID=newNodeLeaf.selectRandSrcDest();

					      }
		else if(key==GLFW_KEY_4&& action == GLFW_PRESS){
		edge.ShowEdgeInfo();
    }
		else if(key==GLFW_KEY_ESCAPE&& action == GLFW_PRESS){//exit the screen
        		glfwSetWindowShouldClose(window, true);
    
	}


}
#endif
