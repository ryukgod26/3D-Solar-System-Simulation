#include "ShaderProgram.h"
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

ShaderProgram::ShaderProgram(std::string vertexShaderPath, std::string fragmentShaderPath){
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vertexShaderFile;
	std::ifstream fragmentShaderFile;

	vertexShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try{
		vertexShaderFile.open(vertexShaderPath);
		fragmentShaderFile.open(fragmentShaderPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vertexShaderFile.rdbuf();
		fShaderStream << fragmentShaderFile.rdbuf();

		vertexShaderFile.close();
		fragmentShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (const std::exception&){
		throw std::runtime_error(
			"Failed to read shader files. Vertex: " + vertexShaderPath + " Fragment: " + fragmentShaderPath
		);
	}


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
		throw std::runtime_error(std::string("Vertex shader compilation failed: ") + infoLog);
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment,1,&fShaderCode,NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

	if (!success){
		glGetShaderInfoLog(fragment,512,NULL,infoLog);
		throw std::runtime_error(std::string("Fragment shader compilation failed: ") + infoLog);
	}

	shaderProgramID = glCreateProgram();
	glAttachShader(shaderProgramID,vertex);
	glAttachShader(shaderProgramID,fragment);
	glLinkProgram(shaderProgramID);

	glGetProgramiv(shaderProgramID,GL_LINK_STATUS,&success);

	if (!success){
		glGetProgramInfoLog(shaderProgramID,512,NULL,infoLog);
		throw std::runtime_error(std::string("Shader program linking failed: ") + infoLog);
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

ShaderProgram::~ShaderProgram() noexcept{
	glDeleteProgram(shaderProgramID);
}

/*
void ShaderProgram::Use() const{
	glUseProgram(shaderProgramID);
}
*/

unsigned int ShaderProgram::GetID() const{
	return shaderProgramID;
}

unsigned int ShaderProgram::GetUniformID(const char* uniformName) const {
	assert(glGetUniformLocation(shaderProgramID, uniformName) != -1);
	return glGetUniformLocation(shaderProgramID, uniformName);
}
