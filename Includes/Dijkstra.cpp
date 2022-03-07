#include"Dijkstra.hpp"
void Dijkstra::findShortestPath(Graph*graph,int src,int dest){
	int graphSize=sizeof(graph)/sizeof(*graph);
	double dist[grapSize];
	for(int i=0;i<graphSize;++i)dist[i]=10000;
	dist[src]=0;// cost of src is 0
}
