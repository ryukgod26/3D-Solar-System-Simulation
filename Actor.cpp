#include "Actor.h"
#include "objload.h"
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <glfw3.h>
#include <assert.h>
#include <glm/gtc/matrix_transform.hpp>

Actor::Actor(const char* objectPath, const Texture& texture)
: texture(texture){
	std::vector<glm::vec3> vertexPositions;
	std::vector<glm::vec3> textureCoordinates;
	std::vector<glm::vec3> normals;
	loadOBJ(objectPath, vertexPositions, textureCoordinates, normals);

	vertexCount = (int)vertexPositions.size();
	assert(vertexCount >= 3);

	glGenVertexArrays(1, & VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1,&VBOVertex);
	glBindBuffer(GL_ARRAY_BUFFER, VBOVertex);
	glBufferData(GL_ARRAY_BUFFER, vertexPositions.size() * sizeof(glm::vec3), vertexPositions.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &VBOTexture);
	glBindBuffer(GL_ARRAY_BUFFER, VBOTexture);
glBufferData(GL_ARRAY_BUFFER, textureCoordinates.size() * sizeof(glm::vec2), textureCoordinates.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1,&VBONormals);
	glBindBuffer(GL_ARRAY_BUFFER, VBONormals);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), normals.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(2,3,GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),0);
	glEnableVertexAttribArray(2);
}

Actor::~Actor() noexcept {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBOVertex);
	glDeleteBuffers(1, &VBOTexture);
	glDeleteBuffers(1, &VBONormals);
}

unsigned int Actor::GetVAO() const {
	return VAO;
}

int Actor::GetVertexCount() const{
	return vertexCount;
}

void Actor::ResetModelMatrix(){
	modelMatrix = glm::mat4(1.0f);
}

void Actor::ApplyTranslation(glm::vec3 translation) {
	modelMatrix = glm::translate(modelMatrix,translation);
}

void Actor::ApplyScale(glm::vec3 scale) {
	modelMatrix = glm::scale(modelMatrix,scale);
}

void Actor::ApplyRotation(float degrees, glm::vec3 axis){
	modelMatrix = glm::rotate(modelMatrix,glm::radians(degrees),axis);
}

const glm::mat4& Actor::GetModelMatrix() const{
	return modelMatrix;
}

const Texture& Actor::GetTexture() const{
	return texture;
}
