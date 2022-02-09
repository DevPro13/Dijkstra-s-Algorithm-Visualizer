#include"Node.h"
NodeTree::NodeTree(){
	root=NULL;
}
void NodeTree::createNode(Queue& Q,double xpos,double ypos){
	if(nodeID!=NULL){
		*nodeID++;
	}
	else{
		nodeID=(int*)malloc(sizeof(int));
		*nodeID=0;
	}
	if(root==NULL){
		root=(Node*)malloc(sizeof(Node));
		root->xpos=xpos;
		root->ypos=ypos;
		root->id=*nodeID;
		Q.Enqueue(root);		
	}
	else{
		Node*newNode=(Node*)malloc(sizeof(Node));
		newNode->xpos=xpos;
		newNode->ypos=ypos;
		newNode->id=*nodeID;
		Q.Enqueue(newNode);
	}
}
void NodeTree::joinNode(Node* node1,Node* node2){
	node1->Edges.push_back(node2);
	node2->Edges.push_back(node1);
}
void NodeTree::flagSrcDest(Node*node1,Node*node2){
	node1->flagSrc=true;
	node2->flagDest=true;
}
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
		delete(head->newTreeNode);
		tmpHead=tmpHead->next;
		delete(head);
		head=tmpHead;
	}
}
void Queue::Display(){
	int count=0;
	while(head!=NULL){
		//std::cout<<"Node is created at "<<head->newTreeNode->xpos<<","<<head->newTreeNode->ypos<<std::endl;
		head=head->next;
		count++;
	}
	std::cout<<count<<std::endl;
}
Node* Queue::Dequeue(int key){
	node*tmpHead=head;
	while(tmpHead!=NULL){
		if(tmpHead->newTreeNode->id==key){
			return tmpHead->newTreeNode;
		}
		tmpHead=tmpHead->next;
	}
	return NULL;
}

