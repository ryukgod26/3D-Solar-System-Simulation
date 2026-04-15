#pragma once


class ShaderProgram{
	public:
		ShaderProgram(const char* vertexShaderPath,const char* fragmentShaderPath);
		ShaderProgram(const ShaderProgram& other) = delete;
		ShaderProgram& operator=(const ShaderProgram& other) = delete;
		~ShaderProgram() noexcept;
		void Use() const;
		unsigned int GetID() const;
	private:
		unsigned int shaderProgramID;
};
