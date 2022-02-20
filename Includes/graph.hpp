#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include<vector>
#include<map>
#include<ctime>
#include<iostream>
typedef std::pair<Node*,std::vector<Node*>> link;
class Edge{
	std::map<Node*,std::vector<Node*>>Edges;
	public:
	Graph();
	void JoinNodesRandom(Queue&Q,int nodes);	
	void ShowEdgeInfo();	
};
class Graph{
	double graph[][]={};
	public:
	Graph();
	void CreateGraph(Edge&edge,int nodes);
	void ShowGraph();

};
#endif
