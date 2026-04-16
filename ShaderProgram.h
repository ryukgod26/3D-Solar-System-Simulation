#pragma once

#include <string>


class ShaderProgram{
	public:
		ShaderProgram(const std::string& vertexShaderPath,const std::string& fragmentShaderPath);
		ShaderProgram(const ShaderProgram& other) = delete;
		ShaderProgram& operator=(const ShaderProgram& other) = delete;
		~ShaderProgram() noexcept;
		void Use() const;
		unsigned int GetID() const;
	private:
		unsigned int shaderProgramID;
};
