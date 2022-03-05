#ifndef VBO_H
#define VBO_H
#include<glad/glad.h>
#include<vector>
class VBO{
public:
    GLuint ID;
    VBO(std::vector<GLfloat>);
    void Bind();
    void Unbind();
    void Delete();
};
#endif
