#pragma once
#include <string>

class Mesh{
	public:
		Mesh(std::string meshPath);
		Mesh(const Mesh& other) = delete;
		Mesh& operator=(const Mesh& other) = delete;
		~Mesh() noexcept;
		unsigned int GetVAO() const;
		int GetVertexCount() const;
	private:
		int vertexCount;

		unsigned int VAO;
		unsigned int VBOVertex;
		unsigned int VBOTexture;
		unsigned int VBONormals;
}
