#pragma once

class Texture{
	public:
		Texture(const char* texturePath);
		~Texture() noexcept;
		Texture(const Texture& other) = delete;
		Texture& operator=(const Texture& other) = delete;
		unsigned int GetID() const;
		int GetWidth() const;
		int GetHeight() const;
		int GetChannelsCount() const;
	private:
		unsigned int textureID = -1;
		int width;
		int height;
		int channelsCount;
};
