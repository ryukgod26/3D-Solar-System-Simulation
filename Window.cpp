#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Window::Window(int windowWidth, int windowHeight, int viewportX,int viewportY, int viewportWidth, int viewportHeight, const std::string title, GLFWmonitor* monitor, GLFWwindow* share)
:
window(nullptr,[](GLFWwindow* window){glfwDestroyWindow(window);}){

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	#endif
	
	window.reset(glfwCreateWindow(windowWidth,windowHeight,title.c_str(),monitor,share));
	if (window == nullptr){
		std::cout<<"Failed to Intialize GLFW.\n";
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window.get());

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout<<"Failed to Intialize GLAD\n";
		exit(EXIT_FAILURE);
	}

	glViewport(viewportX,viewportY,viewportWidth,viewportHeight);
	glClearColor(0.2f,0.3f,0.4f,1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glfwSetFramebufferSizeCallback(window.get(),[](GLFWwindow* window,int width, int height){glViewport(0,0,width,height);});

}

Window::~Window() noexcept
{
	window.reset();
	glfwTerminate();
}

void Window::UseShader(const ShaderProgram& shaderProgram) {
	glUseProgram(shaderProgram.GetID());
}

void Window::DrawActor(const Actor& actor){
	glBindVertexArray(actor.GetVAO());
	glDrawArrays(GL_TRIANGLES, 0, actor.GetVertexCount());
}

void Window::DrawActor(const Actor& actor, const ShaderProgram& shaderProgram){
	UseShader(shaderProgram);
	DrawActor(actor);
}

void Window::SwapBuffers(){
	glfwSwapBuffers(window.get());
}

bool Window::ShouldClose() const{
	return glfwWindowShouldClose(window.get());
}

void Window::ClearBuffers(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
