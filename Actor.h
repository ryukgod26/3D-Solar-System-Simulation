#pragma once
#include<vector>

class Actor{
	public:
		Actor(const char* objectPath);
		void Draw() const;
	private:
		unsigned int vertexCount;

		unsigned int VAO;
		unsigned int VBOVertex;
		unsigned int VBOTexture;
		unsigned int VBONormals;
};
