#ifndef QUEUE_H
#define QUEUE_H
#include"Node.h"
#include<iostream>
#include<stdlib.h>
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
