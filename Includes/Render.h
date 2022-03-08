#ifndef RENDER_H
#define RENDER_H
#include<glad/glad.h>
#include<iostream>
#include<vector>
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Graph.hpp"
const float SCR_WIDTH=1080;
const float SCR_HEIGHT=1080;
class Render{
public://i am bad at coding
    std::vector<GLfloat>NodesPositions;
    std::vector<GLuint>NodePositionIndices;
    std::vector<GLuint>EdgeIndices;
    std::vector<GLfloat>SrcDestVertices;
    std::vector<GLuint>SrcDestIndices;
    std::vector<GLfloat>PathVertices;
    std::vector<GLuint>PathIndices;
    Render();
    void renderNodes(VAO*vaoNodePtr,double xpos,double ypos);
    void renderEdges(Edge&edge,VAO*vaoEdgePtr);
    void renderSrcDestNodes(VAO*vaoSrcDestPtr,double x1,double y1,double x2,double y2);
    void bindVertices(VAO*vao,std::vector<GLfloat>vertices,std::vector<GLuint>indices);
};
#endif
