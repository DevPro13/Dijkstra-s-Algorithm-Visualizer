#ifndef VAO_H
#define VAO_H
#include<glad/glad.h>
#include"VBO.h"
class VAO{
public:
    GLuint ID;
    VAO();
    void LinkVBOpos(VBO&,GLuint);
    void LinkVBOcolor(VBO&,GLuint);
    void Bind();
    void Unbind();
    void Delete();
};
#endif
