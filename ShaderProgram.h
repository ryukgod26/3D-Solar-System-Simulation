#pragma once


class ShaderProgram{
	public:
		ShaderProgram(const cbar* vertexShaderPath,const char* fragmentShaderPath);
		ShaderProgran(const shaderProgram& other); = delete;
		ShaderProgram& operator=(const shaderProgram& other) = delete;
		~ShaderProgran() noexcept;
		void Use() const;
		unsigned int GetID() const;
	private:
		unsigned int shaderProgramID;
}
