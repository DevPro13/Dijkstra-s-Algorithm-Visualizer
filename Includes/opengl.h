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
#include"Render.h"
#include"Graph.hpp"
#include"Dijkstra.hpp"
NodeTree newNodeLeaf;
Queue Q;
Edge edge;
Graph graph;
Render render;
Dijkstra dijkstra(&Q,&render,&graph);
VAO *vaoNodePtr,*vaoEdgePtr,*vaoSrcDestPtr,*vaoPathPtr;
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
         render.renderNodes(vaoNodePtr,xpos,ypos);
	std::cout << "Node created at Position  (" << xpos << "," << ypos <<").\n";
    }
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if(key==GLFW_KEY_1&& action == GLFW_PRESS){//press 1 to add nodes:
	    glfwSetMouseButtonCallback(window,mouse_button_callback_forNodeCreate);
    }
    
		else if(key==GLFW_KEY_2&& action == GLFW_PRESS){//to connect edges
	    			glfwSetMouseButtonCallback(window,NULL);
				edge.JoinNodesRandom(Q,newNodeLeaf.totalNodesCreated());//join nodes randomly using combination
				graph.CreateGraph(edge,newNodeLeaf.totalNodesCreated());//create graph
				graph.ShowGraph();
				render.renderEdges(edge,vaoEdgePtr);
				}
		else if(key==GLFW_KEY_3&& action == GLFW_PRESS){//to select src and destination
						int srcID=newNodeLeaf.selectRandSrcDest();
						int destID=newNodeLeaf.selectRandSrcDest();
						while(srcID==destID)destID=newNodeLeaf.selectRandSrcDest();
						Node* srcnod=Q.Dequeue(srcID);
						Node* destnod=Q.Dequeue(destID);
						newNodeLeaf.flagSrcDest(srcnod,destnod);//flag src and destnition as true
						render.renderSrcDestNodes(vaoSrcDestPtr,srcnod->xpos,srcnod->ypos,destnod->xpos,destnod->ypos);//render src snd dest nodes
						dijkstra.findShortestPath(newNodeLeaf.totalNodesCreated()+1,srcID,destID);
						dijkstra.generatePathNodeVertex(vaoPathPtr);
						newNodeLeaf.flagSrcDest(srcnod,destnod);//flag src and destnition as false again
    }

					     
		else if(key==GLFW_KEY_ESCAPE&& action == GLFW_PRESS){//exit the screen
        		glfwSetWindowShouldClose(window, true);
    
	}
}
void GuideMenu(){
	std::cout<<"\t\tFollow the instrution below to run this program in flow::\n"
		<<"\t\t\tPress 1 to Enable MouseClick Event function loader and click on screen to draw nodes.\n "
		<<"\t\t\tPress 2 to Disable Mouseclick Event function loader and program will automatically join edges between nodes and create graph.\n"
		<<"\t\t\tPress 3 to randomly choose source and destination from the given tree of nodes and apply Dijkstra algorithm to find path between those nodes.\n"
		<<"\t\t\t\t\t\tNote::Node with Green color is source and with Red Color is Destionation\n"
		<<"\t\t\tPress ESC ko Quit and Exit!!\n\n\n";

}
#endif
