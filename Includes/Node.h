#ifndef NODE_H
#define NODE_H
#include<vector>
class Node{
	public:
	vector<Node*>Edges;//stores edges
	bool flagSrc;//flag node is destination
	bool flagDest;//flag node is source
	double xpos,ypos;//node position
	int id;//node id or vertex number
	double weight;
};
class NodeTree{
	Node* root;
	double xpos,ypos;
	static int nodeID;
	public:
	NodeTree(double,double);
	void createNode();
	void joinNode();
	void flagSrcDest();
};
#endif
