#pragma once

class Mesh{
	public:
		Mesh(const char* meshPath);
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
