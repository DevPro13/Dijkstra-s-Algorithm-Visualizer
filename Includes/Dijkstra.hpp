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
				Graph*graph;
			Dijkstra(Graph*grph);
	void findShortestPath(Graph*graph,int V,int src,int dest);
	void generatePathNodeVertex(VAO*vaoPathPtr,Queue*Q,Render*pathObj);//generate path node vertices and indices and render
	int findShortestDist(int*dist,bool*sptVert,bool*isEdge);
};
#endif
