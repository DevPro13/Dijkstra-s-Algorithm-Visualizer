#include"Queue.h"
Queue::Queue():head(NULL){}
void Queue::Enqueue(Node*treeNodeAddress){
	if(head==NULL){
		head=(node*)malloc(sizeof(node));
		head->newTreeNode=treeNodeAddress;
		head->next=NULL;
	}
	else{
		node* tmp=head;
		node*newNode=(node*)malloc(sizeof(node));
		while(tmp!=NULL)tmp=tmp->next;
		newNode->next=NULL;
		newNode->newTreeNode=treeNodeAddress;
		tmp->next=newNode;
	}
}
void Queue::Delete(){
	if(head==NULL)
	{
		std::cout<<"Queue is empty"<<std::endl;
	}
	node*tmpHead=head;
	while(tmpHead->next!=NULL){
		delete(head->treeNodeAddress);
		tmpHead->tmpHead->next;
		delete(head);
		head=tmpHead;
	}
	std::cout<<"All Nodes successfully Deleted"<<std::endl;
}
Node* Queue::Dequeue(int key){
	node*tmpHead=head;
	while(tmpHead!=NULL){
		if(tmpHead->treeNodeAddress->id==key){
			return tmp->treeNodeAddress;
		}
		tmpHead=tmpHead->next;
	}
	return NULL;
}

