#ifndef EBO_H
#define EBO_H
#include<glad/glad.h>
#include<vector>
class EBO{
public:
    GLuint ID;
    EBO(std::vector<GLuint>);
    void Bind();
    void Unbind();
    void Delete();
};
#endif
