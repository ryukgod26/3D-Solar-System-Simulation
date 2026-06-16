#include "Texture.h"
#include "glad/glad.h"
#include "stb_image.h"
#include <iostream>

Texture::Texture(std::string texturePath){
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &channelsCount, 0);
	if (data){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	} else{
		std::cout<< "Failed to load Texture"<< texturePath << std::endl;
		exit(EXIT_FAILURE);
	}

	stbi_image_free(data);
}

Texture::Texture(Texture&& other) noexcept
:
textureID(other.textureID),
	width(other.width),
	height(other.height),
	channelsCount(other.channelsCount)
{

	other.textureID = -1;
	other.width = -1;
	other.height = -1;
	other.channelsCount = -1;
}
Texture& Texture::operator=(Texture&& other) noexcept{
	if(this != &other)
	{
		glDeleteTextures(1, &textureID);
		textureID = other.textureID;
		width = other.width;
		height = other.height;
		channelsCount = other.channelsCount;
		
		other.textureID = -1;
		other.width = -1;
		other.height = -1;
		other.channelsCount = -1;
	}
	return *this;
}

Texture::~Texture() noexcept{
	if (textureID != -1)
	glDeleteTextures(1, &textureID);
}

unsigned int Texture::GetID() const{
	return textureID;
}

int Texture::GetWidth() const{
	return width;
}

int Texture::GetHeight() const{
	return height;
}

int Texture::GetChannelsCount() const{
	return channelsCount;
}
