#include"Dijkstra.hpp"
Dijkstra::Dijkstra(Graph*grph){
	graph=grph;
}
	
/*void Dijkstra::findShortestPath(Graph*graph,int src,int dest){
	int graphSize=sizeof(graph)/sizeof(*graph);
	double dist[grapSize];
	for(int i=0;i<graphSize;++i)dist[i]=INT_MAX;
	dist[src]=0;// cost of src is 0
}*/
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
