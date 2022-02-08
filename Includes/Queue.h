#ifndef QUEUE_H
#define QUEUE_H
#include"Node.h"
#include<iostream>
#include<stdlib.h>
struct node{
	Node* newTreeNode;//for Node address
	struct node* next;//for next node address in linked list
};
class Queue{
	struct node *head;//for head node
	public:
	Queue();
	Enqueue(Node*);
	void Dequeue(int key);//for dequeueAll node address
	void Delete();//delete all Node and nodes in Linked list
};
#endif
