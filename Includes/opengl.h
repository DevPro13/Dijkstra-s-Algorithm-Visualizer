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
NodeTree newNodeLeaf;
Queue Q;
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
    {
       double xpos, ypos;
       //getting cursor position
        glfwGetCursorPos(window, &xpos, &ypos);
     	newNodeLeaf.createNode(Q,xpos,ypos);
	std::cout << "Node created at Position  (" << xpos << "," << ypos <<").\n";
    }
}

void mouse_button_callback_forEdgeJoin(GLFWwindow* window,int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
       double xpos, ypos;
       //getting cursor position
       glfwGetCursorPos(window, &xpos, &ypos);
     //  newNodeLeaf.joinNode(xpos,ypos);
	std::cout << "Node selected at Position  (" << xpos << "," << ypos <<".\n";
    }
}

void mouse_button_callback_forSrcDestSelect(GLFWwindow* window,int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
       double xpos, ypos;
       //getting cursor position
       glfwGetCursorPos(window, &xpos, &ypos);
     //  newNodeLeaf.flagSrcDest(xpos,ypos);
	std::cout << "Node selected at Position  (" << xpos << "," << ypos <<".\n";
    }
}


void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(key==GLFW_KEY_1&& action == GLFW_PRESS){//press 1 to add nodes:
	    glfwSetMouseButtonCallback(window,mouse_button_callback_forNodeCreate);
    }
    
		else if(key==GLFW_KEY_2&& action == GLFW_PRESS){//to connect edges
				std::cout<<"Created nodes are\n\n\n\n\n";
					Q.Display();
					Q.Delete();
	   		// glfwSetMouseButtonCallback(window,mouse_button_callback_forEdgeJoin);
    	}
		else if(key==GLFW_KEY_3&& action == GLFW_PRESS){//to select src and destination
	    			glfwSetMouseButtonCallback(window,mouse_button_callback_forSrcDestSelect);
					      }
		else if(key==GLFW_KEY_4&& action == GLFW_PRESS){
    }
		else if(key==GLFW_KEY_ESCAPE&& action == GLFW_PRESS){//exit the screen
        		glfwSetWindowShouldClose(window, true);
    
	}


}
#endif
