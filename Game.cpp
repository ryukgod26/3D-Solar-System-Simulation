#include "Game.h"
#include "Settings.h"
#ifndef PROJECT_ROOT_DIR
#define PROJECT_ROOT_DIR "."
#endif
#include <fstream>
#include <stdexcept>
#include <vector>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <limits.h>
#include <unistd.h>
#endif

namespace {
std::string NormalizeRoot(const std::string& root) {
	if (root.empty()) {
		return root;
	}

	if (root.back() == '/' || root.back() == '\\') {
		return root;
	}

	return root + "/";
}

std::string JoinPath(const std::string& root, const std::string& relativePath) {
	std::string normalizedRoot = NormalizeRoot(root);
	std::string normalizedRelative = relativePath;
	while (!normalizedRelative.empty() && (normalizedRelative.front() == '/' || normalizedRelative.front() == '\\')) {
		normalizedRelative.erase(normalizedRelative.begin());
	}
	return normalizedRoot + normalizedRelative;
}

bool FileExists(const std::string& path) {
	std::ifstream file(path.c_str());
	return file.good();
}

std::string GetExecutableDirectory() {
#if defined(_WIN32)
	char buffer[MAX_PATH] = {};
	DWORD length = GetModuleFileNameA(nullptr, buffer, MAX_PATH);
	if (length == 0 || length == MAX_PATH) {
		return "";
	}

	std::string executablePath(buffer, length);
	std::string::size_type separator = executablePath.find_last_of("/\\");
	if (separator == std::string::npos) {
		return "";
	}
	return executablePath.substr(0, separator);
#elif defined(__linux__)
	char buffer[PATH_MAX] = {};
	ssize_t length = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
	if (length <= 0) {
		return "";
	}

	buffer[length] = '\0';
	std::string executablePath(buffer);
	std::string::size_type separator = executablePath.find_last_of('/');
	if (separator == std::string::npos) {
		return "";
	}
	return executablePath.substr(0, separator);
#else
	return "";
#endif
}

std::string ResolveAssetRoot() {
	const std::string shaderProbe = JoinPath("ResFiles/Shaders", "VertexShader.vert");
	const std::vector<std::string> candidates = {
		GetExecutableDirectory(),
		".",
		"..",
		PROJECT_ROOT_DIR
	};

	for (const std::string& candidate : candidates) {
		if (candidate.empty()) {
			continue;
		}

		const std::string probePath = JoinPath(candidate, shaderProbe);
		if (FileExists(probePath)) {
			return NormalizeRoot(candidate);
		}
	}

	throw std::runtime_error(
		"Could not locate ResFiles/Shaders/VertexShader.vert. Place ResFiles next to the executable or run from the project root."
	);
}
}

Game::Game(int windowWidth,int windowHeight,int viewportX, int viewportY,int viewportWidth, int viewportHeight,  const std::string title, GLFWmonitor *monitor,GLFWwindow* share) : 
	window(windowWidth,windowHeight,viewportX,viewportY,viewportWidth,viewportHeight,title,monitor,share),shaderProgram(JoinPath(ResolveAssetRoot(), settings::shadersPath + "VertexShader.vert"),JoinPath(ResolveAssetRoot(), settings::shadersPath + "FragmentShader.frag")), 
	camera(settings::cameraInitialPosition, settings::cameraSpeed, settings::cameraYaw, settings::cameraPitch, settings::cameraMaxPitch, settings::cameraSensitivity, settings::cameraFOV, settings::screenRatio, settings::cameraNearPlaneDistance, settings::cameraFarPlaneDistance),
	sphereMesh(JoinPath(ResolveAssetRoot(), settings::meshesPath + "sphere.obj")),
/*	sunTexture(std::string(PROJECT_ROOT_DIR) + settings::texturesPath + "sun.jpeg"),
       	planetTexture(std::string(PROJECT_ROOT_DIR) + settings::texturesPath +"earth.jpeg"), 
	mercuryTexture(std::string(PROJECT_ROOT_DIR) + settings::texturesPath +"mercury.jpg"),
	venusTexture(std::string(PROJECT_ROOT_DIR) + settings::texturesPath + "venus.jpg"),
	marsTexture(std::string(PROJECT_ROOT_DIR) + settings::texturesPath + "mars.jpg"),
	jupiterTexture(std::string(PROJECT_ROOT_DIR) + settings::texturesPath + "jupiter.jpg"),
	saturnTexture(std::string(PROJECT_ROOT_DIR) + settings::texturesPath + "saturn.jpg"),
	uranusTexture(std::string(PROJECT_ROOT_DIR) + settings::texturesPath + "uranus.jpg"),
	neptuneTexture(std::string(PROJECT_ROOT_DIR) + settings::texturesPath + "neptune.jpg"),*/
//	earth(settings::earthOrbitRadius, settings::earthScale, 90, 180),
	//sun("monkey.obj", sunTexture), earth("cube.obj", planetTexture), skyBox("sphere.obj", skyboxTexture),
	
	skyboxTexture(JoinPath(ResolveAssetRoot(), settings::texturePath + "stars.jpeg"))
{
	const std::string assetRoot = ResolveAssetRoot();
	lastMousePosition = window.GetMousePosition();
	lastTime = window.GetElapsedTime();
	skyBox.ApplyScale(glm::vec3{ settings::cameraFarPlaneDistance });

	planets.emplace_back(0, settings::sunScale, 0, settings::sunRotationSpeed);

	planets.emplace_back(settings::mercuryOrbitRadius, settings::mercuryScale, settings::mercuryOrbitSpeed, settings::mercuryRotationSpeed);
	planets.emplace_back(settings::venusOrbitRadius, settings::venusScale, settings::venusOrbitSpeed, -settings::venusRotationSpeed);
	planets.emplace_back(settings::earthOrbitRadius, settings::earthScale, settings::earthOrbitSpeed, settings::earthRotationSpeed);
	planets.emplace_back(settings::marsOrbitRadius, settings::marsScale, settings::marsOrbitSpeed, settings::marsRotationSpeed);
	planets.emplace_back(settings::jupiterOrbitRadius, settings::jupiterScale, settings::jupiterOrbitSpeed, settings::jupiterRotationSpeed);
	planets.emplace_back(settings::saturnOrbitRadius, settings::saturnScale, settings::saturnOrbitSpeed, settings::saturnRotationSpeed);
	planets.emplace_back(settings::uranusOrbitRadius, settings::uranusScale, settings::uranusOrbitSpeed, -settings::uranusRotationSpeed);
	planets.emplace_back(settings::neptuneOrbitRadius, settings::neptuneScale, settings::neptuneOrbitSpeed, settings::neptuneRotationSpeed);

	planetTextures.emplace_back(JoinPath(assetRoot, settings::texturePath + "sun.jpg"));
	planetTextures.emplace_back(JoinPath(assetRoot, settings::texturePath + "venus.jpg"));
	planetTextures.emplace_back(JoinPath(assetRoot, settings::texturePath + "mercury.jpg"));
	planetTextures.emplace_back(JoinPath(assetRoot, settings::texturePath + "earth.jpeg"));
	planetTextures.emplace_back(JoinPath(assetRoot, settings::texturePath + "mars.jpg"));
	planetTextures.emplace_back(JoinPath(assetRoot, settings::texturePath + "jupiter.jpg"));
	planetTextures.emplace_back(JoinPath(assetRoot, settings::texturePath + "saturn.jpg"));
	planetTextures.emplace_back(JoinPath(assetRoot, settings::texturePath + "uranus.jpg"));
	planetTextures.emplace_back(JoinPath(assetRoot, settings::texturePath + "neptune.jpg"));
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
	float now = window.GetElapsedTime();
	float deltaTime = now - lastTime;
	lastTime = now;

	window.ClearBuffers();
	Update(deltaTime);
	Draw(deltaTime);
	window.SwapBuffers();
	window.PollEvents();
}

bool Game::ShouldClose() const
{
	return window.ShouldClose();
}

void Game::Update(float deltaTime)
{
	// Model = glm::mat4(1.0f);
	// Model = glm::translate(Model,glm::vec3(0.0f,0.0f,0.0f));
	// Model = glm::scale(Model,glm::vec3(0.5f,0.5f,0.5f));
	// Model = glm::rotate(Model,glm::radians(150.0f),glm::vec3(0.0f,1.0f,0.0f));
	// Model = glm::rotate(Model,glm::radians(0.0f),glm::vec3(1.0f,0.0f,0.0f));
	// unsigned int matrixID = glGetUniformLocation(shaderProgram.GetID(),"Model");
	// glUniformMatrix4fv(matrixID,1,GL_FALSE,&Model[0][0]);

	if (window.GetElapsedTime() > 1.0f && window.IsKeyPressed(settings::exitKey)) {
		window.Close();
	}

	glm::vec2 mousePosition = window.GetMousePosition();
	glm::vec2 cameraRotationOffset{mousePosition.x - lastMousePosition.x, lastMousePosition.y - mousePosition.y};
	lastMousePosition = mousePosition;
	camera.Rotate(cameraRotationOffset);

	if (window.IsKeyPressed(settings::forwardKey)){
		camera.ProcessKeyboard(Camera::Movement::FORWARD, deltaTime);
	}

	if(window.IsKeyPressed(settings::backwardKey)){
		camera.ProcessKeyboard(Camera::Movement::BACKWARD, deltaTime);
	}

	if(window.IsKeyPressed(settings::leftKey)) {
		camera.ProcessKeyboard(Camera::Movement::LEFT, deltaTime);
	}

	if(window.IsKeyPressed(settings::rightKey)){
		camera.ProcessKeyboard(Camera::Movement::RIGHT, deltaTime);
	}

	if(window.IsKeyPressed(settings::upKey)){
		camera.ProcessKeyboard(Camera::Movement::UP, deltaTime);
	}

	if(window.IsKeyPressed(settings::downKey)){
		camera.ProcessKeyboard(Camera::Movement::DOWN, deltaTime);
	}

// 	sun.ResetModelMatrix();
// //	sun.ApplyTranslation(glm::vec3(0.0f,0.0f,0.0f));
// 	sun.ApplyRotation(float(window.GetElapsedTime() * 5), Camera::worldUp);
// 	sun.ApplyScale(glm::vec3(100.0f));

// 	mercury.resetModelMatrix();
// 	mercury.ApplyRotation(float(window.GetElapsedTime()) * 50, Camera::worldUp);
// 	mercury.ApplyTranslation({ settings::earthOrbitRadius * 0.6f, 0.0f, 0.0f});
// 	mercury.ApplyScale(glm::vec3{ settings::mercuryScale });

// 	venus.ResetModelMatrix();
// 	venus.ApplyRotation(float(window.GetElapsedTime()) * 25, Camera::worldUp);
// 	venus.ApplyTranslation(glm::vec3(0.8f,0.0f,0.0f));
// 	venus.ApplyScale(settings::venusScale);
// 	venus.ApplyRotation(-float(window.GetElapsedTime()) * 30, Camera::worldUp);
// /*
// 	earth.ResetModelMatrix();
// 	earth.ApplyTranslation(glm::vec3(0.0f,0.0f,0.0f));
// 	earth.ApplyRotation(float(window.GetElapsedTime()) * 20, Camera::worldUp);
// 	earth.ApplyScale(settings::earthScale);
// 	earth.ApplyRotation(float(window.GetElapsedTime()) * 20, Camera::worldUp);*/
// 	earth.Update(deltaTime);

	for(Planet& planet : planets){
		planet.Update(deltaTime * timeSpeed);
	}

	
	if(window.IsKeyPressed(settings::timeSpeedUpKey))
		timeSpeed += settings::timeAdjustSpeed;

	if(window.IsKeyPressed(settings::timeSpeedDownKey))
		timeSpeed -= settings::timeAdjustSpeed;
/*	skyBox.ResetModelMatrix();
	skyBox.ApplyScale(glm::vec3{settings::cameraFarPlaneDistance});*/
}

void Game::Draw(float deltaTime)
{
//	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f/600.0f, 0.1f,100.0f);
	glm::mat4 projection = camera.GetPerspectiveMatrix();
//	glm::mat4 view = glm::mat4(1.0f);
//	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -8.0f));
	glm::mat4 viewMatrix = camera.GetViewMatrix();

	window.UseShader(shaderProgram);
	int matrixID = shaderProgram.GetUniformID("MVP");


	for(int i =0; i < planets.size(); i++){
		const glm::mat4& modelMatrix = planets[i].GetModelMatrix();
		shaderProgram.SendUniform<glm::mat4>(matrixID, projection * viewMatrix * modelMatrix);
		window.DrawActor(sphereMesh, planetTextures[i]);
	}

	viewMatrix = glm::mat4(glm::mat3(viewMatrix));
	shaderProgram.SendUniform<glm::mat4>(matrixID, projection * viewMatrix * skyBox.GetModelMatrix());
	window.DrawActor(sphereMesh, skyboxTexture);

	// //glUniformMatrix4fv(matrixID, 1, GL_FALSE, &Model1[0][0]);
	// shaderProgram.SendUniform<glm::mat4>(matrixID,projection * viewMatrix * sun.GetModelMatrix());
	// window.DrawActor(sphereMesh, sunTexture);
	// //glUniformMatrix4fv(matrixID, 1, GL_FALSE, &Model1[0][0]);
	// shaderProgram.SendUniform<glm::mat4>(matrixID, projection * viewMatrix * mercury.GetModelMatrix());
	// window.DrawActor(sphereMesh, mercuryTexture);

	// shaderProgram.SendUniform<glm::mat4>(matrixID, projection * viewMatrix * venus.GetModelMatrix());
	// window.DrawActor(sphereMesh, venusTexture);

	// shaderProgram.SendUniform<glm::mat4>(matrixID, projection * viewMatrix * earth.GetModelMatrix());
	// window.DrawActor(sphereMesh, planetTexture);

	// viewMatrix = glm::mat4(glm::mat3(viewMatrix));
	// shaderProgram.SendUniform<glm::mat4>(matrixID, projection * viewMatrix * skyBox.GetModelMatrix());
	// window.DrawActor(sphereMesh, skyboxTexture);

	/*
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES,0,vertexPositions.size());
	*/
}
