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
	loadOBJ("cube.obj",vertexPositions,textureCoordinates,normals)
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

}

void Game::Draw()
{
	shaderProgram.Use();
}

