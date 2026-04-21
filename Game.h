#pragma once
#include <string>
#include "Window.h"
#include "ShaderProgram.h"
#include <glm/glm.hpp>

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
		std::vector<glm::vec3> vertexPositions;
		std::vector<glm::vec2> textureCoordinates;
		std::vector<glm::vec3> normals;
};
