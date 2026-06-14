#pragma once
#include <string>

class Texture{
	public:
		Texture(std::string texturePath);
		~Texture() noexcept;
		Texture(const Texture& other) = delete;
		Texture& operator=(const Texture& other) = delete;
		unsigned int GetID() const;
		int GetWidth() const;
		int GetHeight() const;
		int GetChannelsCount() const;
		Texture(Texture&& other) noexcept;
		Texture& operator=(Texture&& other) noexcept;
	private:
		unsigned int textureID = -1;
		int width;
		int height;
		int channelsCount;
};
