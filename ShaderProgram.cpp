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

	
}
