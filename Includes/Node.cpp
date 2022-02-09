#inlclude"Node.h"
NodeTree::NodeTree(){
	root=NULL;
}
static void NodeTree::incID(){
	if(nodeID!=NULL){
		*nodeID+=1;
	}
	else{
		nodeID=(int*)malloc(sizeof(int));
		*nodeID=0;
	}
}		
void NodeTree::createNode(Queue Q,double xpos,double ypos){
	incID();
	
	if(root==NULL){
		root=(Node*)malloc(sizeof(Node));
		root->xpos=xpos;
		root->ypos=ypos;
		root->id=nodeID;
		Q.Enqueue(root);
	}
	else{
		Node*newNode=(Node*)malloc(sizeof(Node));
		newNode->xpos=xpos;
		newNode->ypos=ypos;
		newNode->id=nodeID;
		Q.Enqueue(newNode);
	}
}
void NodeTree::joinNode(Node* node1,Node* node2){
	node1->Edges->push_back(node2);
	node2->Edges->push_back(node1);
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

