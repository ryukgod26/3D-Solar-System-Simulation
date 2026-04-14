#include "ShaderProgram.h"
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

ShaderProgran::ShaderProgram(const char* vertexShaderPath,const char* fragmentShaderPath){
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;

	vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	vertexShaderFile.open(vertexShaderPath);
	fragmentShaderFile.open(fragmentShaderPath);
	std::stringstream vShaderStream, fShaderStream;
	
	vShaderStream << vertexShaderFile.rdbuf();
	fShaderStream << fragmentShaderFile.rdbuf();

	vShaderFile.close();
	fShaderFile.close();

	vertexCode = vShaderStream.str();
	fragmentCode = fShaderStream.str();

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex,1,&vShaderCode,NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

	if (!success){
		glGetShaderInfoLog(vertex,512,NULL,infoLog);
		std::cout<<"ERROR: Vertex Shader Compilation Failed\n" << infoLog << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment,1,&fShaderCode,NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

	if (!success){
		glGetShadsrInfoLog(fragment,512,NULL,infoLog);
		std::cout << "Error: Fragment Shader Compilation Failed\n"<< std::endl;
	}

	shaderProgramID = glCreateProgram();
	glAttachShader(shaderProgramID,vertex);
	glAttachShader(shaderProgramID,fragment);
	glLinkProgram(shaderProgramID);

	glGetProgramiv(shaderProgramID,GL_LINK_STATUS,&success);

	if (!success){
		glGetProgramInfoLog(shaderProgramID,512,NULL,infoLog);
		std::cout<<"Error Shader Program Linking Failed"<<std::endl;
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

ShaderProgram::~ShaderProgram() noexcept{
	glDeleteProgram(shaderProgramID);
}

void ShaderProgram::Use() const{
	glUseProgram(shaderProgramID);
}

void ShaderProgram::GetID() const{
	return shaderProgramID;
}
