#inlclude"Node.h"
Queue Q;
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
void NodeTree::createNode(double xpos,double ypos){
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
	
