#pragma once
#include <glm/glm.hpp>

class Camera{
	public:
		enum class Movement{
			FORWARD,
			BACKWARD,
			LEFT,
			RIGHT
		};
		Camera(glm::vec3 position, glm::vec3 worldUp, float movementSpeed, float yaw, float pitch, float mouseSensitivity, float zoom);
		glm::mat4 GetViewMatrix() const;
		void ProcessKeyboard(Movement direction, float deltaTime);
		void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
		void ProcessMouseScroll(float yoffset);
	private:
		glm::vec3 position;
		glm::vec3 front;
		glm::vec3 up;
		glm::vec3 right;
		glm::vec3 worldUp;

		// Euler Angles
		float yaw;
		float pitch;

		float movementSpeed;
		float mouseSensitivity;
		float zoom;
};
