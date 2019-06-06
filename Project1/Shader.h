#pragma once


#ifndef SHADER_H
#define SHADER_H
#pragma comment(lib, "glfw3.lib")
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "glad/glad.h"
#include "glfw3.h"
#include "library/glm/glm/glm.hpp"
#include "library/glm/glm/gtc/matrix_transform.hpp"
#include "library/glm/glm/gtc/type_ptr.hpp"

class Shader
{
public:
	GLuint ShaderProgram;

	void Draw(GLint modeDrow, GLint first, GLint count);
	void Use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setVec2(const std::string &name, const glm::vec2 &value) const;
	void setVec2(const std::string &name, float x, float y) const;
	void setVec3(const std::string &name, const glm::vec3 &value) const;
	void setVec3(const std::string &name, float x, float y, float z) const;
	void setVec4(const std::string &name, const glm::vec4 &value) const;
	void setVec4(const std::string &name, float x, float y, float z, float w) const;
	void setMat2(const std::string &name, const glm::mat2 &mat) const;
	void setMat3(const std::string &name, const glm::mat3 &mat) const;
	void setMat4(const std::string &name, const glm::mat4 &mat) const;

	
	
	Shader(const std::string & VertexShader, const std::string & FragmentShader);
	~Shader();
private:
	bool LoadShader(const std::string& VertexFile, const std::string& FragmentFile, std::string& Vshader, std::string& Fshader);
	void shadErr(const GLuint& shader, std::string type);


};

#endif // !SHADER_H



