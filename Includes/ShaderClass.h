#ifndef SHADER_H
#define SHADER_H
#include<glad/glad.h>
#include<iostream>
#include<sstream>
#include<fstream>
class Shader{
public:
    GLint ID;//refrence ID of Shader Program or shaderProgram
    Shader(const char*,const char*);
    void Activate();//activate shaers program
    void Delete();//Delete shaders program
    void testError();

};
std::string get_file_data(const char*);
#endif

