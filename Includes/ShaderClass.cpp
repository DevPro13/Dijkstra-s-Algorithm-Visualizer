#include"ShaderClass.h"
std::string get_file_data(const char* fname){
	std::fstream fobj;//fstream objects or reading files

        fobj.open(fname);
        std::stringstream fileDataStream;
        fileDataStream<<fobj.rdbuf();
        fobj.close();
        return fileDataStream.str();
}
Shader::Shader(const char*vertFIle,const  char* fragFile){
    //make vertexSrc and fragmentSrc
	std::string vertexCode=get_file_data(vertFIle);
	std::string fragmentCode=get_file_data(fragFile);
  	 const char *vertexSrc=vertexCode.c_str();
  	 const char *fragmentSrc=fragmentCode.c_str();
    // Create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSrc, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);

	// Create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentSrc, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);

	// Create Shader Program Object and get its reference
	ID = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(ID);

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}
void Shader::Activate(){
    glUseProgram(ID);
}
void Shader::Delete(){
    glDeleteProgram(ID);
}
