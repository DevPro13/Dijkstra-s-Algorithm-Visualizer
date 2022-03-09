#ifndef DIJKSTRA
#define DIJKSTRA
#include<vector>
#include"Graph.hpp"
#include"Node.h"
#include"Render.h"
#include"VAO.h"
#include<glad/glad.h>
class Dijkstra{
	public:
	   	std::vector<Node*>PathNodes;	
		Queue*Q;
		Render*pathObj;
		Graph*graph;	
		Dijkstra(Queue*q,Render*path,Graph*grph);
		void findShortestPath(int V,int src,int dest);
		void generatePathNodeVertex(VAO*vaoPathPtr);//generate path node vertices and indices and render
		int findShortestDist(double*dist,bool*sptVert,bool*isEdge,int V);
};
#endif
