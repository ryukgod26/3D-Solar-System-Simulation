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
	constexpr float cameraSpeed = 2.5f;
	constexpr float cameraZoom = 45.0f;
	constexpr glm::vec3 cameraIntialPosition = {0.0f,0.0f,10.0f};
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
	inline constexpr float cameraSpeed = 2.5f;
	inline constexpr float cameraZoom = 45.0f;
	inline constexpr glm::vec3 cameraIntialPosition = {0.0f,0.0f,10.0f};
}
#endif
