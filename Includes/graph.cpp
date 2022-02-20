#include"graph.hpp"
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
		Edges.insert(link(node1,edgesContainer));//link edges
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
	for(int i=0;i<=nodes;++i){
		for(int j=0;j<=nodes;++j){
			graph[i][j]=0;
		}
	}
}

