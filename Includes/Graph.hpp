#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include<vector>
#include<map>
#include<ctime>
#include<iostream>
#include<cmath>
typedef std::pair<Node*,std::vector<Node*>> link;
class Edge{
	std::map<Node*,std::vector<Node*>>Edges;
	public:
	Edge();
	void JoinNodesRandom(Queue&Q,int nodes);	
	void ShowEdgeInfo();	
};
class Graph{
	static int V;
	double graph[][V+1];
	public:
	Graph();
	void CreateGraph(Edge&edge,int nodes);
	void ShowGraph();
	double getNodeDistance(double x1,double y1,double x2,double y2);

};
#endif
