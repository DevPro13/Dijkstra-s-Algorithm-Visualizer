#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<ctime>
#include<stdlib.h>
class Node;
class node;
class NodeTree;
class Queue;
class Node{
	public:
	std::vector<Node*>Edges;//stores edges id
	bool flagSrc=false;//flag node is destination
	bool flagDest=false;//flag node is source
	double xpos,ypos;//node position
	int id;//node id or vertex number
};
class NodeTree{
	Node* root;
	int *nodeID;//for node id and counting number of nodes
	public:
	NodeTree();
	void createNode(Queue& Q,double xpos,double ypos);
	void joinNode(Node*node1,Node*node2);
	void flagSrcDest(Node*node1,Node*node2);
	void getTwoNodeIdRandom(Queue&Q);
	int selectRandSrcDest();
};
//Queue implementation using linked list
class node{
	public:
	Node* newTreeNode;//for Node address
	node* next;//for next node address in linked list
};
class Queue{
	node *head;//for head node
	public:
	Queue();
	void Enqueue(Node*);
	Node*Dequeue(int key);//for dequeueAll node address
	void Delete();//delete all Node and nodes in Linked list
	void Display();
	void DisplayEdgeInfo();
};


#endif
