#include "Window.h"
#include "Settings.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace {
void GLFWErrorCallback(int error, const char* description) {
	std::cerr << "[GLFW] Error " << error << ": " << description << std::endl;
}
}

Window::Window(int windowWidth, int windowHeight, int viewportX,int viewportY, int viewportWidth, int viewportHeight, const std::string title, GLFWmonitor* monitor, GLFWwindow* share)
:
window(nullptr,[](GLFWwindow* window){glfwDestroyWindow(window);}){
	glfwSetErrorCallback(GLFWErrorCallback);

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	#endif
	
	window.reset(glfwCreateWindow(windowWidth,windowHeight,title.c_str(),monitor,share));
	if (window == nullptr){
		std::cerr<<"[Window] Failed to initialize GLFW window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window.get());

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cerr<<"[Window] Failed to initialize GLAD" << std::endl;
		exit(EXIT_FAILURE);
	}

	glViewport(viewportX,viewportY,viewportWidth,viewportHeight);
	glClearColor(0.2f,0.3f,0.4f,1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// if constexpr (settings::captureMouse) {
	if (settings::captureMouse){
		glfwSetInputMode(window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
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

void Window::DrawActor(const Mesh& mesh, const Texture& texture){
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glBindVertexArray(mesh.GetVAO());
	glDrawArrays(GL_TRIANGLES, 0, mesh.GetVertexCount());
}

void Window::DrawActor(const Mesh& mesh, const Texture& texture, const ShaderProgram& shaderProgram){
	UseShader(shaderProgram);
	DrawActor(mesh, texture);
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

float Window::GetElapsedTime() const {
	return (float)glfwGetTime();
}

void Window::PollEvents() const {
	glfwPollEvents();
}

bool Window::IsKeyPressed(int key) const{
	return glfwGetKey(window.get(), key) == GLFW_PRESS;
}

glm::vec2 Window::GetMousePosition() const{
	double xpos, ypos;
	glfwGetCursorPos(window.get(), &xpos, &ypos);
	return glm::vec2(xpos, ypos);
}

void Window::Close() {
	glfwSetWindowShouldClose(window.get(), true);
}
