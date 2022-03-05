#include"Render.h"
Render::Render(){}
void Render::renderNodes(VAO*vaoNodePtr,double xpos,double ypos){
	float xpt=-1.0f+2*(float)xpos/(float)SCR_WIDTH;
		float ypt=1.0f-2*(float)ypos/(float)SCR_HEIGHT;
		std::vector<GLfloat>newVertex={xpt,ypt,0.0f,1.0f,1.0f,1.0f};
		NodesPositions.reserve(NodesPositions.size()+newVertex.size());
		NodesPositions.insert(NodesPositions.end(),newVertex.begin(),newVertex.end());
		if(NodePositionIndices.size()==0){

		NodePositionIndices.push_back(0);
		}
		else{
			NodePositionIndices.push_back(NodePositionIndices.size());
	
		}

		bindVertices(vaoNodePtr,NodesPositions,NodePositionIndices);
	}
void Render::renderEdges(Edge&edge,VAO*vaoEdgePtr){
	for(auto itr=edge.Edges.begin();itr!=edge.Edges.end();++itr){
		for(auto it=itr->second.begin();it!=itr->second.end();++it){
			std::vector<GLuint>indices={(unsigned int)itr->first->id,(unsigned int)(*it)->id};
			EdgeIndices.reserve(EdgeIndices.size()+indices.size());
			EdgeIndices.insert(EdgeIndices.end(),indices.begin(),indices.end());
		}
	}
	bindVertices(vaoEdgePtr,NodesPositions,EdgeIndices);
}
void Render::bindVertices(VAO*vao,std::vector<GLfloat>vertices,std::vector<GLuint>indices){
	vao->Bind();
	VBO vbo(vertices);
	EBO ebo(indices);
	vao->LinkVBOpos(vbo,0);//for position
	vao->LinkVBOcolor(vbo,1);//for color
	vao->Unbind();
	vbo.Unbind();
	ebo.Unbind();
}
