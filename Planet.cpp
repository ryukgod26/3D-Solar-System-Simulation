#include "Planet.h"

Planet::Planet(float orbitRadius, float scale, float orbitSpeedDegrees, float rotationSpeedDegrees) 
	:
		orbitRadius(orbitRadius),
		scale(scale),
		orbitSpeedDegrees(orbitSpeedDegrees),
		rotationSpeedDegrees(rotationSpeedDegrees)
{}

void Planet::Update(float deltaTime) {
	currentRotationDegrees += rotationSpeedDegrees * deltaTime;
	currentOrbitDegrees += orbitSpeedDegrees * deltaTime;

	if (currentRotationDegrees > 360.0f) 
		currentRotationDegrees = currentRotationDegrees - 360.0f;
	else if(currentRotationDegrees < -360.0f)
		currentRotationDegrees = currentRotationDegrees + 360.f;

	if(currentOrbitDegrees > 360.0f)
		currentOrbitDegrees = currentOrbitDegrees - 360.0f;
	else if(currentOrbitDegrees < -360.0f)
		currentOrbitDegrees = currentOrbitDegrees + 360.0f;

	ResetModelMatrix();
	ApplyRotation(currentOrbitDegrees, {0.0f,1.0f,0.0f});
	ApplyTranslation({orbitRadius, 0.0f, 0.0f});
	ApplyScale(glm::vec3{ scale });
	ApplyRotation(currentRotationDegrees, {0.0f, 1.0f, 0.0f});
}
