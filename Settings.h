#pragma once
#include "glm/glm.hpp"
#include <string>

# ifdef __WIN32__

namespace settings{

	extern std::string texturePath;
	extern std::string meshesPath;
	extern std::string shadersPath;

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
	const glm::vec3 cameraInitialPosition = { 0.0f,0.0f,150.0f };
	constexpr int forwardKey = 87;
	constexpr int backwardKey = 83;
	constexpr int rightKey = 68;
	constexpr int leftKey = 65;
	constexpr int upKey = 69;
	constexpr int downKey = 81;
	constexpr int exitKey = 256;
	constexpr int timeSpeedUpKey = 334;
	constexpr int timeSpeedDownKey = 333;

	constexpr bool captureMouse = true;

	constexpr float timeAdjustSpeed = 0.01f;

	constexpr float earthOrbitRadius = 300.0f;
	constexpr float mercuryOrbitRadius = earthOrbitRadius * 0.6f;
	constexpr float venusOrbitRadius = earthOrbitRadius * 0.8f;
	constexpr float marsOrbitRadius = earthOrbitRadius * 1.3f;
	constexpr float jupiterOrbitRadius = earthOrbitRadius * 1.6f;
	constexpr float saturnOrbitRadius = earthOrbitRadius * 2.3f;
	constexpr float uranusOrbitRadius = earthOrbitRadius * 2.6f;
	constexpr float neptuneOrbitRadius = earthOrbitRadius * 3.3f;

	constexpr float earthScale = 10.0f;
	constexpr float sunScale = 100.0f;
	constexpr float mercuryScale = earthScale * 0.3f;
	constexpr float venusScale = earthScale * 0.9f;
	constexpr float marsScale = earthScale * 0.5f;
	constexpr float jupiterScale = earthScale * 5.0f;
	constexpr float saturnScale = earthScale * 4.0f;
	constexpr float uranusScale = earthScale * 2.5f;
	constexpr float neptuneScale = earthScale * 2.3f;

	constexpr float earthRotationSpeed = 20.0f;
	constexpr float sunRotationSpeed = earthRotationSpeed * 0.037;
	constexpr float mercuryRotationSpeed = earthRotationSpeed * 17.241f;
	constexpr float venusRotationSpeed = earthRotationSpeed * 4.115f;
	constexpr float marsRotationSpeed = earthRotationSpeed * 0.960f;
	constexpr float jupiterRotationSpeed = earthRotationSpeed * 2.403f;
	constexpr float saturnRotationSpeed = earthRotationSpeed * 2.183f;
	constexpr float uranusRotationSpeed = earthRotationSpeed * 1.412f;
	constexpr float neptuneRotationSpeed = earthRotationSpeed * 1.501f;

	constexpr float earthOrbitSpeed = 20.0f;
	constexpr float mercuryOrbitSpeed = earthOrbitSpeed * 4.149f;
	constexpr float venusOrbitSpeed = earthOrbitSpeed * 1.623f;
	constexpr float marsOrbitSpeed = earthOrbitSpeed * 0.531f;
	constexpr float jupiterOrbitSpeed = earthOrbitSpeed * 0.084f;
	constexpr float saturnOrbitSpeed = earthOrbitSpeed * 0.033f;
	constexpr float uranusOrbitSpeed = earthOrbitSpeed * 0.011f;
	constexpr float neptuneOrbitSpeed = earthOrbitSpeed * 0.006f;

	static_assert(windowWidth > 0 && windowHeight > 0);
	static_assert(viewportWidth > 0 && viewportHeight > 0);
	static_assert(cameraNearPlaneDistance > 0.0f);
	static_assert(cameraNearPlaneDistance < cameraFarPlaneDistance);
	static_assert(cameraSensitivity > 0.0f);
}


#else
namespace settings{

	extern std::string texturePath;
	extern std::string meshesPath;
	extern std::string shadersPath;

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
	constexpr int timeSpeedUpKey = 334;
	constexpr int timeSpeedDownKey = 333;

	inline constexpr bool captureMouse = true;

	inline constexpr float timeAdjustSpeed = 0.01f;

	inline constexpr float earthOrbitRadius = 300.0f;
	inline constexpr float mercuryOrbitRadius = earthOrbitRadius * 0.6f;
	inline constexpr float venusOrbitRadius = earthOrbitRadius * 0.8f;
	inline constexpr float marsOrbitRadius = earthOrbitRadius * 1.3f;
	inline constexpr float jupiterOrbitRadius = earthOrbitRadius * 1.6f;
	inline constexpr float saturnOrbitRadius = earthOrbitRadius * 2.3f;
	inline constexpr float uranusOrbitRadius = earthOrbitRadius * 2.6f;
	inline constexpr float neptuneOrbitRadius = earthOrbitRadius * 3.3f;

	inline constexpr float earthScale = 10.0f;
	inline constexpr float sunScale = 100.0f;
	inline constexpr float mercuryScale = earthScale * 0.3f;
	inline constexpr float venusScale = earthScale * 0.9f;
	inline constexpr float marsScale = earthScale * 0.5f;
	inline constexpr float jupiterScale = earthScale * 5.0f;
	inline constexpr float saturnScale = earthScale * 4.0f;
	inline constexpr float uranusScale = earthScale * 2.5f;
	inline constexpr float neptuneScale = earthScale * 2.3f;

	inline constexpr float earthOrbitSpeed = 20.0f;
	inline constexpr float mercuryOrbitSpeed = earthOrbitSpeed * 4.149f;
	inline constexpr float venusOrbitSpeed = earthOrbitSpeed * 1.623f;
	inline constexpr float marsOrbitSpeed = earthOrbitSpeed * 0.531f;
	inline constexpr float jupiterOrbitSpeed = earthOrbitSpeed * 0.084f;
	inline constexpr float saturnOrbitSpeed = earthOrbitSpeed * 0.033f;
	inline constexpr float uranusOrbitSpeed = earthOrbitSpeed * 0.011f;
	inline constexpr float neptuneOrbitSpeed = earthOrbitSpeed * 0.006f;

	inline constexpr float earthRotationSpeed = 20.0f;
	inline constexpr float sunRotationSpeed = earthRotationSpeed * 0.037;
	inline constexpr float mercuryRotationSpeed = earthRotationSpeed * 17.241f;
	inline constexpr float venusRotationSpeed = earthRotationSpeed * 4.115f;
	inline constexpr float marsRotationSpeed = earthRotationSpeed * 0.960f;
	inline constexpr float jupiterRotationSpeed = earthRotationSpeed * 2.403f;
	inline constexpr float saturnRotationSpeed = earthRotationSpeed * 2.183f;
	inline constexpr float uranusRotationSpeed = earthRotationSpeed * 1.412f;
	inline constexpr float neptuneRotationSpeed = earthRotationSpeed * 1.501f;

	static_assert(windowWidth > 0 && windowHeight > 0);
	static_assert(viewportWidth > 0 && viewportHeight > 0);
	static_assert(cameraNearPlaneDistance > 0.0f);
	static_assert(cameraNearPlaneDistance < cameraFarPlaneDistance);
	static_assert(cameraSensitivity > 0.0f);
}
#endif
