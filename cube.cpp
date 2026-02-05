#define GL_GLEXT_PROTOTYPES

#include<GLFW/glfw3.h>
#include<iostream>

const char *vertexShaderSrc = "";

const char *fragmentShaderSrc = "";

int main() {
	if(!glfwInit()){
		std::cout<<"Failed to Intialize GLFW"<<std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow* window = glfwCreateWindow(800,600,"First Cube",NULL,NULL);

	if (window == NULL){
		std::cout<<"Failed to Create Glfw window"<<std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader,1,&vertexShaderSrc,NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader,1,&fragmentShaderSrc,NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram,vertexShader);
	glAttachShader(shaderProgram,fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f,-1.0f,-1.0f,//t1
		-1.0f,-1.0f,1.0f,
		-1.0f,1.0f,1.0f,
		1.0f,1.0f,-1.0f,//t2
		-1.0f,-1.0f,-1.0f,
		-1.0f,1.0f,-1.0f,
		1.0f,-1.0f,1.0f,//t3
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f,1.0f,-1.0f,//t4
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,//t5
		-1.0f,1.0f,1.0f,
		-1.0f,1.0f,-1.0f,
		1.0f,-1.0f,1.0f//t6
		-1.0f,-1.0f,1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,1.0f,1.0f,//t7
		-1.0f,-1.0f,1.0f,
		1.0f,-1.0f,1.0f,
		1.0f,1.0f,1.0f,//t8
		1.0f,-1.0f,-1.0f,
		1.0f,1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,//t9
		1.0f,1.0f,1.0f,
		1.0f,-1.0f,1.0f,
		1.0f,1.0f,1.0f,//t10
		1.0f,1.0f,-1.0f,
		-1.0f,1.0f,-1.0f,
		1.0f,1.0f,1.0f,//t11
		-1.0,1.0f,-1.0f,
		-1.0f,1.0f,1.0f,
		1.0f,1.0f,1.0f,//t12
		-1.0f,1.0f,1.0f,
		1.0f,-1.0f,1.0f,
	};
	

	unsigned int VBA,VBO;

}
