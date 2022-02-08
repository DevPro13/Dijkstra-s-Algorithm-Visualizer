#include"VAO.h"
VAO::VAO(){
	glGenVertexArrays(1,&ID);
}
void VAO::LinkVBOpos(VBO& vbo,GLuint layout){
	vbo.Bind();
	glVertexAttribPointer(layout,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)0);
	glEnableVertexAttribArray(layout);
	vbo.Unbind();	
}
void VAO::LinkVBOcolor(VBO& vbo,GLuint layout){
	vbo.Bind();
	glVertexAttribPointer(layout,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(sizeof(float)*3));
	glEnableVertexAttribArray(layout);
	vbo.Unbind();	
}
void VAO::LinkVBOtexture(VBO& vbo,GLuint layout){
	vbo.Bind();
	glVertexAttribPointer(layout,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(sizeof(float)*6));
	glEnableVertexAttribArray(layout);
	vbo.Unbind();	
}
void VAO::Bind(){
	glBindVertexArray(ID);
}
void VAO::Unbind(){
	glBindVertexArray(0);
}
void VAO::Delete(){
	glDeleteVertexArrays(1,&ID);
}

