#pragma once
#include <glad/glad.h>
#include <glfw3.h>
#include <memory>
#include <functional>
#include <string>

class Game{
	public:
		Game(int width, int height, GLFWmonitor *monitor=nullptr,GLFWwindow *share=nullptr);
	
	private:
		std::unique_ptr<GLFWwindow, std::function<void(GlFWwindow*)>> window;
}
