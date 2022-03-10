#include"Graph.hpp"
Edge::Edge(){}
void Edge::JoinNodesRandom(Queue&Q,int nodes){
	for(int i=0;i<nodes;++i)
		{std::vector<Node*>edgesContainer;
		Node*node1=Q.Dequeue(i);
		srand(time(0));
		for(int j=i+1;j<=nodes;++j){
		if(rand()%2==1||rand()%13==0||rand()%4==3){
		std::cout<<"Node id "<<i<<" is joined with node id "<<j<<std::endl;
		edgesContainer.push_back(Q.Dequeue(j));
		}
       	}	
		Edges.insert(linkEdge(node1,edgesContainer));//link edges
   }
}
void Edge::ShowEdgeInfo(){
	for(auto it=Edges.begin();it!=Edges.end();++it){
		std::cout<<it->first->id<<" is joined with\n"<<std::endl;
		for(auto itr=it->second.begin();itr!=it->second.end();++itr){
			std::cout<<(*itr)->id<<std::endl;
		}
	}
}
//for graph
Graph::Graph(){}
void Graph::CreateGraph(Edge&edge,int nodes){
	V=nodes+1;
	double tempGraph[V][V];
	graph=(double*)malloc(V*V*sizeof(double));
	for(int i=0;i<=nodes;++i){
		for(int j=0;j<=nodes;++j){
		tempGraph[i][j]=0;
	}
	}
	for(auto it=edge.Edges.begin();it!=edge.Edges.end();++it){
		for(auto itr=it->second.begin();itr!=it->second.end();++itr){
			double dist=getNodeDistance(it->first->xpos,it->first->ypos,(*itr)->xpos,(*itr)->ypos);
			tempGraph[it->first->id][(*itr)->id]=dist;
			tempGraph[(*itr)->id][it->first->id]=dist;
			std::cout<<"distance between nose id "<<it->first->id<<" and node id "<<(*itr)->id<<" is "<<dist<<std::endl;
		}
	}
	for(int i=0;i<=nodes;++i){
		for(int j=0;j<=nodes;++j){
	*(graph+i*V+j)=tempGraph[i][j];
		}
	}
}
double Graph::getNodeDistance(double x1,double y1,double x2,double y2){
	return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}
void Graph::ShowGraph(){
	for(int i=0;i<V;++i){
		for(int j=0;j<V;++j){
		std::cout<<*(graph+i*V+j)<<"\t";
		}
		std::cout<<"\n";
	}
}
Graph::~Graph(){
	free(graph);//free allocated memory
}
