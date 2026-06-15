#include "Mesh.h"
#include <glad/glad.h>
#include <glfw3.h>
#include <vector>
#include <vector>
#include "objload.h"
#include "glm.hpp"

Mesh::Mesh(std::string meshPath){
	std::vector<glm::vec3> vertexPositions;
	std::vector<glm::vec2> textureCoordinates;
	std::vector<glm::vec3> normals;
	loadOBJ(meshPath.c_str(), vertexPositions, textureCoordinates, normals);

	vertexCount = (int)vertexPositions.size();
	assert(vertexCount >= 3);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBOVertex);
	glBindBuffer(GL_ARRAY_BUFFER, VBOVertex);
	glBufferData(GL_ARRAY_BUFFER, vertexPositions.size() * sizeof(glm::vec3), vertexPositions.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	
	glGenBuffers(1, &VBOTexture);
	glBindBuffer(GL_ARRAY_BUFFER, VBOTexture);
	glBufferData(GL_ARRAY_BUFFER, textureCoordinates.size() * sizeof(glm::vec2), textureCoordinates.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &VBONormals);
	glBindBuffer(GL_ARRAY_BUFFER, VBONormals);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), normals.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
}


Mesh::~Mesh() noexcept{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBOVertex);
	glDeleteBuffers(1, &VBOTexture);
	glDeleteBuffers(1, &VBONormals);
}

unsigned int Mesh::GetVAO() const{
	return VAO;
}

int Mesh::GetVertexCount() const{
	return vertexCount;
}
