#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<stdlib.h>
#include<vector>
class Node;
class node;
class NodeTree;
class Queue;
class Node{
	public:
	vector<Node*>Edges;//stores edges
	bool flagSrc=false;//flag node is destination
	bool flagDest=false;//flag node is source
	double xpos,ypos;//node position
	int id;//node id or vertex number
};
class NodeTree{
	Node* root;
	static int *nodeID;
	public:
	NodeTree();
	void createNode(Queue,double,double);
	void joinNode(Node*,Node*);
	void flagSrcDest(Node*,Node*);
	static void incID();
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
};


#endif
