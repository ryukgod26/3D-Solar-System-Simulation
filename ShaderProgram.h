#pragma once
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <string>


class ShaderProgram{
	public:
		ShaderProgram(std::string vertexShaderPath,std::string fragmentShaderPath);
		ShaderProgram(const ShaderProgram& other) = delete;
		ShaderProgram& operator=(const ShaderProgram& other) = delete;
		~ShaderProgram() noexcept;
//		void Use() const;
		unsigned int GetID() const;
		int GetUniformID(const char* uniformName) const;

		template <typename T>
		void SendUniform(int uniformID, const T& value){
			(void)uniformID;
			(void)value;
		}
	private:
		unsigned int shaderProgramID;
};

template<>
inline void ShaderProgram::SendUniform<glm::mat4>(int uniformID, const glm::mat4& value){
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, &value[0][0]);
}

template<>
inline void ShaderProgram::SendUniform<unsigned int>(int uniformID, const unsigned int& value){
	glUniform1ui(uniformID, value);
}
