#ifndef NODE_H
#define NODE_H
#include<vector>
#include"Queue.h"
class Node{
	public:
	vector<Node*>Edges;//stores edges
	bool flagSrc=false;//flag node is destination
	bool flagDest=false;//flag node is source
	double xpos,ypos;//node position
	int id;//node id or vertex number
	double weight;
};
class NodeTree:public class Queue{
	Node* root;
	static int *nodeID;
	public:
	NodeTree();
	void createNode(double,double);
	void joinNode(Node*,Node*);
	void flagSrcDest(Node*,Node*);
	static void incID();
};
#endif
