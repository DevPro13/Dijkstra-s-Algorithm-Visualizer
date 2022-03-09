#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include<vector>
#include<map>
#include<ctime>
#include<iostream>
#include<stdlib.h>
#include<cmath>
typedef std::pair<Node*,std::vector<Node*>>linkEdge;
class Edge{
	public:
	std::map<Node*,std::vector<Node*>>Edges;//create a map which has a key as node and value as vector of nodes
	Edge();
	void JoinNodesRandom(Queue&Q,int nodes);	
	void ShowEdgeInfo();	
};
class Graph{
	public:
	int V; //total vertex.. one node=1 vertex..so basically total num. of nodes
	double *graph;
	Graph();
	~Graph();
	void CreateGraph(Edge&edge,int nodes);
	void ShowGraph();
	double getNodeDistance(double x1,double y1,double x2,double y2);

};
#endif
