#pragma once
#include <string>
#include "Window.h"
#include "Actor.h"
#include "ShaderProgram.h"
#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"
#include "Texture.h"

class Game{
	public:
		Game(int windowWidth, int windowHeight,int viewportX, int viewportY, int viewportWidth, int viewportHeight,const std::string title ,struct GLFWmonitor *monitor=nullptr,struct GLFWwindow *share=nullptr);
		Game(const Game& other) = delete;
		Game& operator=(const Game& other) = delete;
//		~Game() noexcept;
		void Tick();
		bool ShouldClose() const;
	
	private:
		void Update();
		void Draw();
		Window window;
		ShaderProgram shaderProgram;
		Camera camera;
		/*
		std::vector<glm::vec3> vertexPositions;
		std::vector<glm::vec2> textureCoordinates;
		std::vector<glm::vec3> normals;

		unsigned int VAO;
		unsigned int VBO;
		unsigned int VBOColor;
		*/

		Texture planetTexture;
		Actor objActor;
		Actor objActor2;
		Actor dome;
		glm::vec2 lastMousePosition;

/*
		//camera
		glm::vec3 camPos = glm::vec3(0.0f,0.0f,3.0f);
		glm::vec3 camDirection = glm::vec3(0.0f,0.0f,-1.0f);
		glm::vec3 camUp = glm::vec3(0.0f,1.0f,0.0f);
		static constexpr float camSpeed = 0.005f;
*/
};
