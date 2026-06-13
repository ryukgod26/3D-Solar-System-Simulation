#pragma once
#include "glm/glm.hpp"

# ifdef __WIN32__

namespace settings{
	constexpr int windowWidth = 1280;
	constexpr int windowHeight = 720;
	constexpr int viewportX = 0;
	constexpr int viewportY = 0;
	constexpr int viewportWidth = 1280;
	constexpr int viewportHeight = 720;
	constexpr char windowTitle[] = "3D Solar System";
	constexpr float cameraYaw = -90.0f;
	constexpr float cameraPitch = 0.0f;
	constexpr float cameraSensitivity = 0.05f;
	constexpr float cameraSpeed = 30.0f;
//	constexpr float cameraZoom = 45.0f;
	constexpr float cameraFOV = 45.0f;                         
	constexpr float cameraMaxPitch = 70.0f;
	constexpr float cameraNearPlaneDistance = 0.3f;
	constexpr float cameraFarPlaneDistance = 10000.0f;         
	constexpr float screenRatio = float(windowWidth) / float(windowHeight);
	constexpr glm::vec3 cameraInitialPosition = { 0.0f,0.0f,150.0f };
	constexpr int forwardKey = 87;
	constexpr int backwardKey = 83;
	constexpr int rightKey = 68;
	constexpr int leftKey = 65;
	constexpr int upKey = 69;
	constexpr int downKey = 81;
	constexpr int exitKey = 256;

	constexpr bool captureMouse = true;


	static_assert(windowWidth > 0 && windowHeight > 0);
	static_assert(viewportWidth > 0 && viewportHeight > 0);
	static_assert(cameraNearPlaneDistance > 0.0f);
	static_assert(cameraNearPlaneDistance < cameraFarPlaneDistance);
	static_assert(cameraSensitivity > 0.0f);
}


#else
namespace settings{
	inline constexpr int windowWidth = 1280;
	inline constexpr int windowHeight = 720;
	inline constexpr int viewportX = 0;
	inline constexpr int viewportY = 0;
	inline constexpr int viewportWidth = 1280;
	inline constexpr int viewportHeight = 720;
	inline constexpr char windowTitle[] = "3D Solar System";
	inline constexpr float cameraYaw = -90.0f;
	inline constexpr float cameraPitch = 0.0f;
	inline constexpr float cameraSensitivity = 0.05f;
	inline constexpr float cameraSpeed = 30.0f;
//	inline constexpr float cameraZoom = 45.0f;

	inline constexpr float cameraMaxPitch = 70.0f;
	inline constexpr float cameraFOV = 45.0f;
	inline constexpr float cameraNearPlaneDistance = 0.3f;
	inline constexpr float cameraFarPlaneDistance = 10000.0f;
	inline constexpr float screenRatio = float(windowWidth) / float(windowHeight);
	inline constexpr glm::vec3 cameraInitialPosition = {0.0f,0.0f,150.0f};
	inline constexpr int forwardKey = 87;
	inline constexpr int backwardKey = 83;
	inline constexpr int rightKey = 68;
	inline constexpr int leftKey = 65;
	inline constexpr int upKey = 69;
	inline constexpr int downKey = 81;
	inline constexpr int exitKey = 256;

	inline constexpr bool captureMouse = true;

	static_assert(windowWidth > 0 && windowHeight > 0);
	static_assert(viewportWidth > 0 && viewportHeight > 0);
	static_assert(cameraNearPlaneDistance > 0.0f);
	static_assert(cameraNearPlaneDistance < cameraFarPlaneDistance);
	static_assert(cameraSensitivity > 0.0f);
}
#endif
