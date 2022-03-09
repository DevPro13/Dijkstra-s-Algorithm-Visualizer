#include"Dijkstra.hpp"
	Dijkstra::Dijkstra(Queue*q,Render*path,Graph*grph):graph(grph),Q(q),pathObj(path){}
int Dijkstra::findShortestDist(double*dist,bool*sptVert,bool*isEdge,int V){
        int index=0;
        double min=100000;
        for(int i=0;i<V;++i){
                if(min>=*(dist+i)&&!*(sptVert+i)&&*(isEdge+i))
                {
                        index=i;
                        min=*(dist+i);
                }
}
return index;
}
void Dijkstra::findShortestPath(int V,int src,int dest){
	PathNodes.resize(0);//resize path node container
        double dist[V];
        dist[src]=0;//source distance 0
        bool sptVert[V];//flag true is node visited
        bool isEdge[V];//flag is either nodes has edges
        for(int i=0;i<V;++i){
                dist[i]=100000;
                sptVert[i]=false;
                isEdge[i]=false;
        }
        isEdge[src]=true;
	dist[src]=0;
        for(int count=0;count<V;++count){
                int u=findShortestDist(&dist[0],&sptVert[0],&isEdge[0],V);
                for(int i=0;i<V;++i)isEdge[i]=false;
                PathNodes.push_back(Q->Dequeue(u));
                sptVert[u]=true;
                        for(int v=0;v<V;v++){
                        if(*(graph->graph+u*V+v)!=0)isEdge[v]=true;
                if((*(graph->graph+u*V+v)!=0)&&(dist[u]+*(graph->graph+u*V+v)<dist[v])){
                        dist[v]=dist[u]+*(graph->graph+u*V+v);
                        }
                }
                if(u==dest){break;}
        }
	//for(auto it=PathNodes.begin();it!=PathNodes.end();++it)std::cout<<(*it)->id<<"\t"<<dist[(*it)->id]<<std::endl;//display final path output
}
void Dijkstra::generatePathNodeVertex(VAO*vaoPathPtr){
	if(PathNodes.size()<=1&&!PathNodes.back()->flagDest){
		std::cout<<"THere might be one missing path between nodes"
			<<"\nReturning.......\n";
		return;
	}
	if(pathObj->PathIndices.size()!=0){
		pathObj->PathIndices.resize(0);
		pathObj->PathVertices.resize(0);
		}
	auto it=PathNodes.begin();
	while(it!=PathNodes.end()){
		float xSrc=-1.0f+2*(float)(*it)->xpos/(float)SCR_WIDTH;
		float ySrc=1.0f-2*(float)(*it)->ypos/(float)SCR_HEIGHT;
		std::vector<GLfloat>tempVertex={xSrc,ySrc,0.0f,1.0f,0.0f,1.0f};
		pathObj->PathVertices.reserve(pathObj->PathVertices.size()+tempVertex.size());
		pathObj->PathVertices.insert(pathObj->PathVertices.end(),tempVertex.begin(),tempVertex.end());
		it++;
	}
	for(int i=0;i<PathNodes.size()-1;++i){

	pathObj->PathIndices.push_back(i);
	pathObj->PathIndices.push_back(i+1);
	pathObj->bindVertices(vaoPathPtr,pathObj->PathVertices,pathObj->PathIndices);//finally render
	}
}
