#include "Game.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Game::Game(int width,int height, const std::string title, GLFWmonitor *monitor,GLFWwindow* share) : window(nullptr,[](GLFWwindow* window){ 
	glfwDestroyWindow(window);
})
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	#endif
	
	window.reset(glfwCreateWindow(width,height,title.c_str(),monitor,share));

	if(window == nullptr){
		std::cout<<"Failed to Intialize GLFW.\n";
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window.get());
	
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		std::cout<<"Failed to Intialize GLAD\n";
		exit(EXIT_FAILURE);
	}

	glViewport(0,0,800,600);
	glClearColor(.2f,.3f,.5f,1.0f);
	glfwSetFramebufferSizeCallback(window.get(),
			[](GLFWwindow* window,int width,int height){
			glViewport(0,0,width,height);
			});

}
