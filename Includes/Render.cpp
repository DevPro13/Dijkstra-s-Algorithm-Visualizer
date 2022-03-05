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
		vaoNodePtr->Bind();
		VBO vbo1(NodesPositions);
		EBO ebo1(NodePositionIndices);
		vaoNodePtr->LinkVBOpos(vbo1,0);//for position
		vaoNodePtr->LinkVBOcolor(vbo1,1);//for color
		vaoNodePtr->Unbind();
		vbo1.Unbind();
		ebo1.Unbind();
}
