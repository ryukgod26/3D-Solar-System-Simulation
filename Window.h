#pragma once
#include <string>
#include <memory>
#include <functional>

class Window{
	public:
		Window(int windowWidth,int windowHeight, int viewportX, int viewportY, int viewportWidth,int viewportHeight,const std::string title, struct GLFWmonitor* monitor = nullptr,struct GLFWwindow* share = nullptr);
		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;
		~Window() noexcept;
		void SwapBuffers() const;
		bool ShouldClose() const;
	private:
		std::unique_ptr<GLFWwindow, std::function<void(GLFWwindow*)>> window;

};
