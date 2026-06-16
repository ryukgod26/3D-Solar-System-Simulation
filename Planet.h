#pragma once
#include "Actor.h"

class Planet : public Actor{
	public:
		Planet(float orbitRadius, float scale, float orbitSpeedDegrees, float rotationSpeedDegrees);
		void Update(float deltaTime);
	private:
		const float orbitRadius;
		const float scale;
		const float orbitSpeedDegrees;
		const float rotationSpeedDegrees;
		float currentOrbitDegrees = 0.0f;
		float currentRotationDegrees = 0.0f;
};
