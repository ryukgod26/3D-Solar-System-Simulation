#pragma once
#include<vector>
#include <glm/glm.hpp>
#include "Texture.h"

class Actor{
	public:
		Actor(const char* objectPath, const Texture& texture);
		Actor(const Actor& other) = delete;
		Actor& operator=(const Actor& other) = delete;
		virtual ~Actor() noexcept;
		unsigned int GetVAO() const;
		int GetVertexCount() const;
:q

		void ResetModelMatrix();
		void ApplyTranslation(glm::vec3 translation);
		void ApplyScale(glm::vec3 scale);
		void ApplyRotation(float degrees, glm::vec3 axis);
		const glm::mat4& GetModelMatrix const;
		const Texture& GetTexture() const;
	private:
		int vertexCount;
		const Texture& texture;

		unsigned int VAO;
		unsigned int VBOVertex;
		unsigned int VBOTexture;
		unsigned int VBONormals;
};
