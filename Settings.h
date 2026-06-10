#pragma once
#include "glm/glm.hpp"

# ifdef __WIN32__

namespace settings{
	constexpr int windowWidth = 800;
	constexpr int windowHeight = 600;
	constexpr int viewportX = 0;
	constexpr int viewportY = 0;
	constexpr int viewportWidth = 800;
	constexpr int viewportHeight = 600;
	constexpr char windowTitle[] = "3D Solar System";
	constexpr float cameraYaw = -90.0f;
	constexpr float cameraPitch = 0.0f;
	constexpr float cameraSensitivity = 0.1f;
	constexpr float cameraSpeed = 4.0f;
//	constexpr float cameraZoom = 45.0f;
	constexpr float cameraFOV = 45.0f;                         
	constexpr float cameraNearPlaneDistance = 0.3f;
	constexpr float cameraFarPlaneDistance = 100.0f;         
	constexpr float screenRatio = float(windowWidth) / float(windowHeight);
	constexpr glm::vec3 cameraIntialPosition = {0.0f,0.0f,10.0f};
	constexpr int forwardKey = 87;
	constexpr int backwardKey = 83;
	constexpr int rightKey = 68;
	constexpr int leftKey = 65;
	constexpr int upKey = 69;
	constexpr int downKey = 81;


	static_assert(windowWidth > 0 && windowHeight > 0);
	static_assert(viewportWidth > 0 && viewportHeight > 0);
	static_assert(cameraNearPlaneDistance > 0.0f);
	static_assert(cameraNearPlaneDistance < cameraFarPlaneDistance);
	static_assert(cameraSensitivity > 0.0f);
}


#else
namespace settings{
	inline constexpr int windowWidth = 800;
	inline constexpr int windowHeight = 600;
	inline constexpr int viewportX = 0;
	inline constexpr int viewportY = 0;
	inline constexpr int viewportWidth = 800;
	inline constexpr int viewportHeight = 600;
	inline constexpr char windowTitle[] = "3D Solar System";
	inline constexpr float cameraYaw = -90.0f;
	inline constexpr float cameraPitch = 0.0f;
	inline constexpr float cameraSensitivity = 0.1f;
	inline constexpr float cameraSpeed = 4.0f;
//	inline constexpr float cameraZoom = 45.0f;

	inline constexpr float cameraFOV = 45.0f;
	inline constexpr float cameraNearPlaneDistance = 0.3f;
	inline constexpr float cameraFarPlaneDistance = 100.0f;
	inline constexpr float screenRatio = float(windowWidth) / float(windowHeight);
	inline constexpr glm::vec3 cameraIntialPosition = {0.0f,0.0f,10.0f};
	inline constexpr int forwardKey = 87;
	inline constexpr int backwardKey = 83;
	inline constexpr int rightKey = 68;
	inline constexpr int leftKey = 65;
	inline constexpr int upKey = 69;
	inline constexpr int downKey = 81;

	static_assert(windowWidth > 0 && windowHeight > 0);
	static_assert(viewportWidth > 0 && viewportHeight > 0);
	static_assert(cameraNearPlaneDistance > 0.0f);
	static_assert(cameraNearPlaneDistance < cameraFarPlaneDistance);
	static_assert(cameraSensitivity > 0.0f);
}
#endif
