#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 worldUp, float movementSpeed, float yaw, float pitch, float mouseSensitivity, float zoom, float screenRatio, float nearPlaneDistance, float farPlaneDistance) : 
	position(position),
//	front(glm::vec3(0.0f, 0.0f, -1.0f)),
//	up(up),
	worldUp(worldUp),
	yaw(yaw),
	pitch(pitch),
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
		case Movement::Forward:
			position += front * velocity;
			break;
		case Movement::Backward:
			position -= front * velocity;
			break;
		case Movement::Right:
			position += right * velocity;
			break;
		case Movement::Left:
			position -= right * velocity;
			break;
	}
}

glm::mat4 Camera::GetViewMatrix() const {
	return glm::lookAt(position, position + front, up);
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch){
	xoffset *= mouseSensitivity;
	yoffset *= mouseSensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (constrainPitch) {
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
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
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	front = glm::normalize(front);
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}

glm::mat4 Camera::GetPerspectiveMatrix() const{
	return glm::perspective(glm::radians(zoom),screenRatio,nearPlaneDistance, farPlaneDistance);
}
