#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 worldUp, float movementSpeed, float yaw, float pitch, float maxPitch, float mouseSensitivity, float zoom, float screenRatio, float nearPlaneDistance, float farPlaneDistance) : 
	position(position),
//	front(glm::vec3(0.0f, 0.0f, -1.0f)),
//	up(up),
	worldUp(worldUp),
	yaw(yaw),
	pitch(pitch),
	maxPitch(maxPitch),
	movementSpeed(movementSpeed),
	mouseSensitivity(mouseSensitivity),
	zoom(zoom),
	screenRatio(screenRatio),
	nearPlaneDistance(nearPlaneDistance),
	farPlaneDistance(farPlaneDistance)
{
	UpdateCameraVectors():
}

void Camera::ProcessKeyboard(Movement direction, float deltaTime){
	float velocity = movementSpeed * deltaTime;
	switch(direction) {
		case Movement::FORWARD:
			position += front * velocity;
			break;
		case Movement::BACKWARD:
			position -= front * velocity;
			break;
		case Movement::RIGHT:
			position += right * velocity;
			break;
		case Movement::LEFT:
			position -= right * velocity;
			break;
		case Movement::UP:
			position += worldUp * velocity;
			break;
		case Movement::DOWN:
			position -= worldUp * velocity;
			break;
	}
}

glm::mat4 Camera::GetViewMatrix() const {
	return glm::lookAt(position, position + front, up);
}

void Camera::Rotate(glm::vec2 rotationOffset, bool constrainPitch){
	rotationOffset *= mouseSensitivity;

	yaw += rotationOffset.x;
	pitch += rotationOffset.y;

	if (constrainPitch) {
		if (pitch > maxPitch)
			pitch = maxPitch;
		if (pitch < -maxPitch)
			pitch = -maxPitch;
	}

	UpdateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset){
	zoom -= (float)yoffset;
	if (zoom < 1.0f)
		zoom = 1.0f;
	if (zoom > 45.0f)
		zoom = 45.0f;
}

void Camera::UpdateCameraVectors(){
	glm::vec3 newFront;
	newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	newFront.y = sin(glm::radians(pitch));
	newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	front = glm::normalize(newFront);
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}

glm::mat4 Camera::GetPerspectiveMatrix() const{
	return glm::perspective(glm::radians(zoom),screenRatio,nearPlaneDistance, farPlaneDistance);
}
