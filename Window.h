#pragma once
#include <string>
#include <memory>
#include <functional>
#include "Actor.h"
#include "ShaderProgram.h"
#include <glm/vec2.hpp>
#include "Mesh.h"
#include "Texture.h"

class Window{
	public:
		Window(int windowWidth,int windowHeight, int viewportX, int viewportY, int viewportWidth,int viewportHeight,const std::string title, struct GLFWmonitor* monitor = nullptr,struct GLFWwindow* share = nullptr);
		Window(const Window& other) = delete;
		Window& operator=(const Window& other) = delete;
		~Window() noexcept;

		void UseShader(const ShaderProgram& shaderProgram);
		void DrawActor(const Mesh& mesh, const Texture& texture);
		void DrawActor(const Mesh& mesh, const Texture& texture, const ShaderProgram& shaderProgram);

		void SwapBuffers();
		bool ShouldClose() const;
		void ClearBuffers();
		float GetElapsedTime() const;
		void PollEvents() const;
		bool IsKeyPressed(int key) const;
		glm::vec2 GetMousePosition() const;
		void Close();
	private:
		std::unique_ptr<GLFWwindow, std::function<void(GLFWwindow*)>> window;

};
