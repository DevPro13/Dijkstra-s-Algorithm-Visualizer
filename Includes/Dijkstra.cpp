#include"Dijkstra.hpp"
Dijkstra::Dijkstra(Graph*grph){
	graph=grph;
}
int Dijkstra::findShortestDist(int*dist,bool*sptVert,bool*isEdge){
        int index=0;
        int min=10000;
        for(int i=0;i<V;++i){
                if(min>=*(dist+i)&&!*(sptVert+i)&&*(isEdge+i))
                {
                        index=i;
                        min=*(dist+i);
                }
}
return index;
}
void Dijkstra::findShortestPath(int*graph,int src,int dest){
        int dist[V];
        dist[src]=0;//source distance 0
        bool sptVert[V];
        bool isEdge[V];
        for(int i=0;i<V;++i){
                dist[i]=10000;
                sptVert[i]=false;
                isEdge[i]=false;
        }
        isEdge[src]=true;
	dist[src]=0;
        for(int count=0;count<V;++count){
                int u=findShortestDist(&dist[0],&sptVert[0],&isEdge[0]);
                for(int i=0;i<V;++i)isEdge[i]=false;
                PathNodes.push_back(Q->Dequeue(u));
                sptVert[u]=true;
                        for(int v=0;v<V;v++){
                        if(graph[u][v]!=0)isEdge[v]=true;
                if((graph[u][v]!=0)&&(dist[u]+graph[u][v])<dist[v]){
                        dist[v]=dist[u]+graph[u][v];
                        }
                }
                if(u==dest){break;}
        }
}



void Dijkstra::generatePathNodeVertex(VAO*vaoPathPtr,Queue*Q,Render*pathObj){

	if(pathObj->PathIndices.size()!=0){
		pathObj->PathIndices.resize(0);
		pathObj->PathVertices.resize(0);
		}
	auto it=PathNodes.begin();
	while(it!=PathNodes.end()){
		float xSrc=-1.0f+2*(float)(*it)->xpos/(float)SCR_WIDTH;
		float ySrc=1.0f-2*(float)(*it)->ypos/(float)SCR_HEIGHT;
		std::vector<GLfloat>tempVertex={xSrc,ySrc,0.0f,1.0f,1.0f,0.0f};
		pathObj->PathVertices.reserve(pathObj->PathVertices.size()+tempVertex.size());
		pathObj->PathVertices.insert(pathObj->PathVertices.end(),tempVertex.begin(),tempVertex.end());
		it++;
	}
	for(int i=0;i<PathNodes.size()-1;++i){
	pathObj->PathIndices.push_back(i);
	pathObj->PathIndices.push_back(i+1);
	}
	pathObj->bindVertices(vaoPathPtr,pathObj->PathVertices,pathObj->PathIndices);//finally render
}
