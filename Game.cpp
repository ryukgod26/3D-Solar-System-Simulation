#include "Game.h"
#include "Settings.h"

#ifndef PROJECT_ROOT_DIR
#define PROJECT_ROOT_DIR "."
#endif

Game::Game(int windowWidth,int windowHeight,int viewportX, int viewportY,int viewportWidth, int viewportHeight,  const std::string title, GLFWmonitor *monitor,GLFWwindow* share) : 
	window(windowWidth,windowHeight,viewportX,viewportY,viewportWidth,viewportHeight,title,monitor,share),shaderProgram(std::string(PROJECT_ROOT_DIR) + "/ResFiles/Shaders/VertexShader.vert",std::string(PROJECT_ROOT_DIR) + "/ResFiles/Shaders/FragmentShader.frag"), 
	camera(settings::cameraInitialPosition, settings::cameraSpeed, seetings::cameraYaw, settings::cameraPitch, settings::cameraMaxPitch, settings::cameraSensitivity, settings::cameraFOV, settings::screenRatio, settings::cameraNearPlaneDistance, settings::cameraFarPlaneDistance),
	sphereMesh("ResFiles/Meshes/sphere.obj"),
	sunTexture("ResFiles/Textures/sun.jpeg"), planetTexture("ResFiles/Textures/earth.jpeg"), mercuryTexture("ResFiles/Textures/mercury.jpg"),skyboxTexture("ResFiles/Textures/stars.jpeg"), 
	//sun("monkey.obj", sunTexture), earth("cube.obj", planetTexture), skyBox("sphere.obj", skyboxTexture),
{
	lastMousePosition = window.GetMousePosition();
	skybox.ApplyScale(glm::vec3{ settings::cameraFarPlaneDistance });
	/*
	std::string objPath = std::string(PROJECT_ROOT_DIR) + "/monkey.obj";
	if (!loadOBJ(objPath.c_str(),vertexPositions,textureCoordinates,normals)){
		throw std::runtime_error("Failed to load OBJ file: " + objPath);
	}
	glGenVertexArrays(1,&VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1,&VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER,vertexPositions.size() * sizeof(glm::vec3),&vertexPositions[0],GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(GLfloat),(void*)0);

	glGenBuffers(1,&VBOColor);
	glBindBuffer(GL_ARRAY_BUFFER,VBOColor);
	glBufferData(GL_ARRAY_BUFFER,normals.size() * sizeof(glm::vec3),&normals[0],GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat) * 3, (void*)0 );
	glBindVertexArray(0);
	*/

/*	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);*/
	

}

void Game::Tick()
{
	window.ClearBuffers();
	Update();
	Draw();
	window.SwapBuffers();
	window.glfwPollEvents();
}

bool Game::ShouldClose() const
{
	return window.ShouldClose();
}

void Game::Update()
{
	// Model = glm::mat4(1.0f);
	// Model = glm::translate(Model,glm::vec3(0.0f,0.0f,0.0f));
	// Model = glm::scale(Model,glm::vec3(0.5f,0.5f,0.5f));
	// Model = glm::rotate(Model,glm::radians(150.0f),glm::vec3(0.0f,1.0f,0.0f));
	// Model = glm::rotate(Model,glm::radians(0.0f),glm::vec3(1.0f,0.0f,0.0f));
	// unsigned int matrixID = glGetUniformLocation(shaderProgram.GetID(),"Model");
	// glUniformMatrix4fv(matrixID,1,GL_FALSE,&Model[0][0]);

	if(window.IsKeyPressed(settings::exitKey)){
		window.Close();
	}

	glm::vec2 mousePosition = window.GetMousePosition();
	glm::vec2 cameraRotationOffset{mousePosition.x - lastMousePosition.x, lastMousePosition.y - mousePosition.y};
	lastMousePosition = mousePosition;
	camera.Rotate(cameraRotationOffset);

	if (window.IsKeyPressed(settings::forwardKey)){
		camera.ProcessKeyboard(Camera::Movement::FORWARD, 0.016f);
	}

	if(window.IsKeyPressed(settings::backwardKey)){
		camera.ProcessKeyboard(Camera::Movement::BACKWARD, 0.016f);
	}

	if(window.IsKeyPressed(settings::leftKey)) {
		camera.ProcessKeyboard(Camera::Movement::LEFT, 0.016f);
	}

	if(window.IsKeyPressed(settings::rightKey)){
		camera.ProcessKeyboard(Camera::Movement::RIGHT, 0.016f);
	}

	if(window.IsKeyPressed(settings::upKey)){
		camera.ProcessKeyboard(Camera::Movement::UP, 0.016f);
	}

	if(window.IsKeyPressed(settings::downKey)){
		camera.ProcessKeyboard(Camera::Movement::DOWN, 0.016f)
	}

	sun.ResetModelMatrix();
//	sun.ApplyTranslation(glm::vec3(0.0f,0.0f,0.0f));
	sun.ApplyRotation(float(window.GetElapsedTime() * 5), Camera::worldUp);
	sun.ApplyScale(glm::vec3(100.0f));

	earth.ResetModelMatrix();
	earth.ApplyTranslation(glm::vec3(0.0f,0.0f,0.0f));
	earth.ApplyRotation(float(window.GetElapsedTime()) * 20, Camera::worldUp);
	earth.ApplyScale(settings::earthScale);
	earth.ApplyRotation(float(window.GetElapsedTime()) * 20, Camera::worldUp);

	mercury.resetModelMatrix();
	mercury.ApplyRotation(float(window.GetElapsedTime()) * 50, Camera::worldUp);
	mercury.ApplyTranslation({ settings::earthOrbitRadius * 0.6f, 0.0f, 0.0f});
	mercury.ApplyScale(glm::vec3{ settings::earthScale * 0.5f });

/*	skyBox.ResetModelMatrix();
	skyBox.ApplyScale(glm::vec3{settings::cameraFarPlaneDistance});*/
}

void Game::Draw()
{
//	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f,100.0f);
	glm::mat4 projection = camera.GetPerspectiveMatrix();
//	glm::mat4 view = glm::mat4(1.0f);
//	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -8.0f));
	glm::mat4 viewMatrix = camera.GetViewMatrix();

	window.UseShader(shaderProgram);
	unsigned int matrixID = shaderProgram.GetUniformID("MVP");

	//glUniformMatrix4fv(matrixID, 1, GL_FALSE, &Model1[0][0]);
	shaderProgram.SendUniform<glm::mat4>(matrixID,projection * viewMatrix * sun.GetModelMatrix());
	window.DrawActor(sun, sphereMesh, sunTexture);
	//glUniformMatrix4fv(matrixID, 1, GL_FALSE, &Model1[0][0]);
	shaderProgram.SendUniform<glm::mat4>(matrixID, projection * viewMatrix * earth.GetModelMatrix());
	window.DrawActor(earth, sphereMesh, planetTexture);

	shaderProgram.SendUniform<glm::mat4>(matrixID, projection * viewMatrix * mercury.GetModelMatrix());
	window.DrawActor(mercury, sphereMesh, mercuryTexture);

	viewMatrix = glm::mat4(glm::mat3(viewMatrix));
	shaderProgram.SendUniform<glm::mat4>(matrixID, projection * viewMatrix * skyBox.GetModelMatrix());
	window.DrawActor(skyBox, sphereMesh, skyboxTexture);

	/*
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES,0,vertexPositions.size());
	*/
}
