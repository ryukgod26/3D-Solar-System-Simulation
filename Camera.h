#pragma once
#include <glm/glm.hpp>

class Camera{
	public:
		static const glm::vec3 worldUp;
		enum class Movement{
			FORWARD,
			BACKWARD,
			LEFT,
			RIGHT,
			UP,
			DOWN
		};
		Camera(glm::vec3 position, float movementSpeed, float yaw, float pitch, float maxPitch, float mouseSensitivity, float zoom, float screenRatio, float nearPlaneDistance = 0.1f, float farPlaneDistance = 100.0f);
		glm::mat4 GetViewMatrix() const;
		glm::mat4 GetPerspectiveMatrix() const;
		void ProcessKeyboard(Movement direction, float deltaTime);
		void Rotate(glm::vec2 rotationOffset, bool constrainPitch = true);
		void ProcessMouseScroll(float yoffset);
	private:
		glm::vec3 position;
		glm::vec3 front = glm::vec3(0.0f,0.0f,-1.0f);
		glm::vec3 up;
		glm::vec3 right;

		// Euler Angles
		float yaw;
		float pitch;
		float maxPitch;

		float movementSpeed;
		float mouseSensitivity;
		float zoom;

		float screenRatio;
		float nearPlaneDistance;
		float farPlaneDistance;

		void UpdateCameraVectors();

};
