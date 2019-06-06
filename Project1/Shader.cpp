#include "Shader.h"

Shader::Shader(const std::string & VertexShaderFile, const std::string & FragmentShaderFile)
{

	std::string Vshader, Fshader;
	//�������� �� ����������
	if (!LoadShader(VertexShaderFile, FragmentShaderFile, Vshader, Fshader))
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		
	}
		
	GLuint VertexShader;
	GLuint FragmentShader;
	//����������� �� string � char* ��� ������������� � glShaderSource
	const char* vs = Vshader.c_str();
	//����������� �� string � char* ��� ������������� � glShaderSource
	const char* fs = Fshader.c_str();

	//�������� ������� "��������� ������"
	VertexShader = glCreateShader(GL_VERTEX_SHADER); 
	//������������� ������� ����� �� �����
	glShaderSource(VertexShader, 1,  &vs, NULL);
	//���������� �������
	glCompileShader(VertexShader);

	

	//�������� ������� "����������� ������"
	FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//������������� ������� ����� �� �����
	glShaderSource(FragmentShader, 1, &fs, NULL);
	//���������� �������
	glCompileShader(FragmentShader);

	
	this->ShaderProgram = glCreateProgram();
	glAttachShader(this->ShaderProgram, VertexShader);
	glAttachShader(this->ShaderProgram, FragmentShader);
	// �������� ������������ � ���������� ��������
	glLinkProgram(this->ShaderProgram);

	shadErr(FragmentShader, "FRAGMENT");
	shadErr(VertexShader, "VERTEX");
	shadErr(this->ShaderProgram, "PROGRAM");
	
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);
	Vshader.clear();
	Fshader.clear();
}

Shader::~Shader()
{
}

//������������ � ����� ���� ��� ������ �������
void Shader::Draw(GLint modeDrow, GLint first, GLint count)
{	
	glDrawArrays(modeDrow, first, count);
}

void Shader::Use()
{
	glUseProgram(this->ShaderProgram);
}

//�������� �������� � ��������� ����������. ���������� true ���� �������� ����������� �������
bool Shader::LoadShader(const std::string& VertexFile, const std::string& FragmentFile, std::string& Vshader, std::string& Fshader)
{

	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		vShaderFile.open(VertexFile);
		fShaderFile.open(FragmentFile);

		std::stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		Vshader = vShaderStream.str();
		Fshader = fShaderStream.str();

		vShaderFile.close();
		fShaderFile.close();
	}
	catch (std::ifstream::failure e)
	{
		return false;
	}
	

	return true;
}

//������� ������ � �������, ���� �� ���, �� ������ �� ������� 
void Shader::shadErr(const GLuint& shader, std::string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	
}

void Shader::setBool(const std::string &name, bool value) const
{

	glUniform1i(glGetUniformLocation(this->ShaderProgram, name.c_str()), (int)value);

}

void Shader::setInt(const std::string &name, int value) const
{

	glUniform1i(glGetUniformLocation(this->ShaderProgram, name.c_str()), value);

}

void Shader::setFloat(const std::string &name, float value) const
{

	glUniform1f(glGetUniformLocation(this->ShaderProgram, name.c_str()), value);

}

void Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{
	glUniform2fv(glGetUniformLocation(ShaderProgram, name.c_str()), 1, &value[0]);
}

void Shader::setVec2(const std::string &name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(ShaderProgram, name.c_str()), x, y);
}
// ------------------------------------------------------------------------
void Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{
	glUniform3fv(glGetUniformLocation(ShaderProgram, name.c_str()), 1, &value[0]);
}

void Shader::setVec3(const std::string &name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(ShaderProgram, name.c_str()), x, y, z);
}
// ------------------------------------------------------------------------
void Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{
	glUniform4fv(glGetUniformLocation(ShaderProgram, name.c_str()), 1, &value[0]);
}

void Shader::setVec4(const std::string &name, float x, float y, float z, float w) const
{
	glUniform4f(glGetUniformLocation(ShaderProgram, name.c_str()), x, y, z, w);
}
// ------------------------------------------------------------------------
void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(ShaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(ShaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(ShaderProgram, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}