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
void Render::renderSrcDestNodes(VAO*vaoSrcDestPtr,double x1,double y1,double x2,double y2){
	float xpt1=-1.0f+2*(float)x1/(float)SCR_WIDTH;
	float ypt1=1.0f-2*(float)y1/(float)SCR_HEIGHT;
	float xpt2=-1.0f+2*(float)x2/(float)SCR_WIDTH;
	float ypt2=1.0f-2*(float)y2/(float)SCR_HEIGHT;
	SrcDestVertices={xpt1,ypt1,0.0f,0.0f,1.0f,0.0f,
		       	xpt2,ypt2,0.0f,1.0f,0.0f,0.0f};
	SrcDestIndices={0,1};
	bindVertices(vaoSrcDestPtr,SrcDestVertices,SrcDestIndices);
}
//void Render::renderDijkstrasPath(VAO*vaoPathPtr){

//}
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
