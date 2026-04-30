#include "Game.h"
#include "objload.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#ifndef PROJECT_ROOT_DIR
#define PROJECT_ROOT_DIR "."
#endif

Game::Game(int windowWidth,int windowHeight,int viewportX, int viewportY,int viewportWidth, int viewportHeight,  const std::string title, GLFWmonitor *monitor,GLFWwindow* share) : 
	window(windowWidth,windowHeight,viewportX,viewportY,viewportWidth,viewportHeight,title,monitor,share),shaderProgram(std::string(PROJECT_ROOT_DIR) + "/ResFiles/Shaders/VertexShader.vert",std::string(PROJECT_ROOT_DIR) + "/ResFiles/Shaders/FragmentShader.frag")
{
	std::string objPath = std::string(PROJECT_ROOT_DIR) + "/cube.obj";
	if (!loadOBJ(objPath.c_str(),vertexPositions,textureCoordinates,normals)){
		throw std::runtime_error("Failed to load OBJ file: " + objPath);
	}
	glGenVertexArrays(1,&VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1,&VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER,vertexPositions.size() * sizeof(glm::vec3),&vertexPositions[0],GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(GLfloat),(void*)0);

	glGenBuffers(1,&VBOColor);
	glBindBuffer(GL_ARRAY_BUFFER,VBOColor);
	glBufferData(GL_ARRAY_BUFFER,normals.size() * sizeof(glm::vec3),&normals[0],GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat) * 3, (void*)0 );
	glBindVertexArray(0);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	

}

void Game::Tick()
{
	window.ClearBuffers();
	Update();
	Draw();
	window.SwapBuffers();
	glfwPollEvents();
}

bool Game::ShouldClose() const
{
	return window.ShouldClose();
}

void Game::Update()
{
	Model = glm::mat4(1.0f);
	Model = glm::translate(Model,glm::vec3(0.0f,0.0f,0.0f));
	Model = glm::scale(Model,glm::vec3(0.5f,0.5f,0.5f));
	Model = glm::rotate(Model,glm::radians(150.0f),glm::vec3(0.0f,1.0f,0.0f));
	Model = glm::rotate(Model,glm::radians(0.0f),glm::vec3(1.0f,0.0f,0.0f));
	unsigned int matrixID = glGetUniformLocation(shaderProgram.GetID(),"Model");
	glUniformMatrix4fv(matrixID,1,GL_FALSE,&Model[0][0]);
}

void Game::Draw()
{
	shaderProgram.Use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES,0,vertexPositions.size());
}

