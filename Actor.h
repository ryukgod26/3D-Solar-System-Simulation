#pragma once
#include<vector>

class Actor{
	public:
		Actor(const char* objectPath);
		Actor(const Actor& other) = delete;
		Actor& operator=(const Actor& other) = delete;
		virtual ~Actor() noexcept;
		unsigned int GetVAO() const;
		unsigned int GetVertexCount() const;
	private:
		unsigned int vertexCount;

		unsigned int VAO;
		unsigned int VBOVertex;
		unsigned int VBOTexture;
		unsigned int VBONormals;
};
