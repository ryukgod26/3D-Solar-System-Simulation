#define GL_TEXT_PROTOTYPES

#include<GLFW/glfw3.h>
#include<iostream>

const char *vertexShaderSource = "#version 330 core"
				"layout (location = 0) in vec3 aPos;\n"
		"void main(){\n"
		"gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);}\0";

const char *fragmentShaderSource = "#version 330 core\n"
				"out vec4 FragColor;\n"
				"void main() {\n"
				"FragColor = vec4(1.0f,0.5f,0.6f,1.0f);\n;\n"
				"}\0";


int main() {
	if (!glfwInit()){
		std::cout<<"Failed to Intialize GLFW"<<std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800,600,"Test Triangle",NULL,NULL);
	if (window == NULL) {
		std::cout<<"Failed to Create GLFW Window"<<std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram,vertexShader);
	glAttachShader(shaderProgram,fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	unsigned int VBO;
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
	};
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	glBufferData(GL_BUFFER_ARRAY,sizeof(vertices),vertices,GL_STATIC_DRAW);

	glEnableVertexPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(float),(void *)0);
	glEnableVertexAttribArray(0);
	
	while(!glfwWindowShouldClose(window)){
		glClearColor(0.2f,0.3f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArray(1,&VAO);
	glDeleteBuffers(1,&VBO);
	glDeleteProgram(shaderProgram);
	glfwTerminate();

	return 0;

}
