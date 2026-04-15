#include "Game.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Game::Game(int windowWidth,int windowHeight,int viewportX, int viewportY,int viewportWidth, int viewportHeight,  const std::string title, GLFWmonitor *monitor,GLFWwindow* share) : 
	window(windowWidth,windowHeight,viewportX,viewportY,viewportWidth,viewportHeight,title,monitor,share)
{
}

Game::~Game() noexcept
{
	window.reset();
	glfwTerminate();
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

}

