#include"Node.h"
NodeTree::NodeTree(){
	root=NULL;
}
void NodeTree::createNode(Queue& Q,double xpos,double ypos){
	if(nodeID!=NULL){
		*nodeID+=1;
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
	node1->Edges->Enqueue(node2);
}
void NodeTree::flagSrcDest(Node*node1,Node*node2){
	node1->flagSrc=true;
	node2->flagDest=true;
}
void NodeTree::getTwoNodeIdRandom(Queue&Q){
	//randoming get two node id.. using and join them
	int numNodes=*nodeID;
	Queue edges[numNodes];
	for(int i=0;i<=numNodes;++i)
	{	Q.Dequeue(i)->Edges=&edges[i];
		srand(time(0));
		for(int j=i+1;j<=numNodes;++j){
			if(rand()%2==1||rand()%13==0||rand()%4==3){
				std::cout<<"Node id "<<i<<" is joined with node id "<<j<<std::endl;
				joinNode(Q.Dequeue(i),Q.Dequeue(j));//join them
									}
		}
	}
}
int NodeTree::selectRandSrcDest(){
	srand(time(0));
	return rand()%(*nodeID+1);
}
	

//for Queue list
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
		while(tmp->next!=NULL)tmp=tmp->next;
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
	while(tmpHead!=NULL){
		delete(head->newTreeNode);
		tmpHead=tmpHead->next;
		delete(head);
		head=tmpHead;
	}
}
void Queue::Display(){
	int count=0;
	while(head!=NULL){
		std::cout<<"Node od id "<<head->newTreeNode->id<<" is created at "<<head->newTreeNode->xpos<<","<<head->newTreeNode->ypos<<std::endl;
		
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
void Queue::DisplayEdgeInfo(){
	if(head==NULL){
			std::cout<<"No nodes created"<<std::endl;
			return;
	}
	node*tmphead=head;
	while(tmphead!=NULL){
		node*tmpedge=tmphead->newTreeNode->Edges->head;
		std::cout<<"node "<<tmphead->newTreeNode->id<<"is edged with"<<tmpedge->newTreeNode<<std::endl;
		tmphead=tmphead->next;
	}
}


