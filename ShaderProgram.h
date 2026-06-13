#pragma once
#include <assert.h>
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
		unsigned int GetUniformID(const char* uniformName) const;

		template <typename T>
		void SendUniform(unsigned int uniformID, const T& value){
			assert(false);
		}

		template<>
		void SendUniform<glm::mat4>(unsigned int uniformID, const glm::mat4& value){
			glUniformMatrix4fv(uniformID, 1, GL_FALSE, &value[0][0]);
		}

		template<>
		void SendUniform<unsigned int>(unsigned int uniformID, const unsigned int& value){
			glUniform1ui(uniformID, value);
		}
	private:
		unsigned int shaderProgramID;
};
