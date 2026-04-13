#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <functional>
#include <string>

class Game{
	public:
		Game(int width, int height,const std::string title ,GLFWmonitor *monitor=nullptr,GLFWwindow *share=nullptr);
		Game(const Game& other) = delete;
		Game& operator=(const Game& other) = delete;
		~Game() noexcept;
	
	private:
		std::unique_ptr<GLFWwindow, std::function<void(GLFWwindow*)>> window;
};
