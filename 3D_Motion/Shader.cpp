#include "Shader.h"
#include<iostream>
#include<fstream>

Shader::Shader(const string& filename)
{
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(filename+".vs.txt"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(filename+".fs.txt"), GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < num_shaders; i++)
		glAttachShader(m_program, m_shaders[i]);

	glBindAttribLocation(m_program, 0, "position");
	glBindAttribLocation(m_program, 1, "texCoord");

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed..");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program validation failed..");

	m_uniforms[m_uniform] = glGetUniformLocation(m_program, "transform");
}

void Shader::update(Transform& transform, Camera& cam)
{
	glm::mat4 t= transform.getModel()*cam.getView();
	glUniformMatrix4fv(m_uniforms[m_uniform], num_uniforms, GL_FALSE, &t[0][0]);
}

void Shader::bind()
{
	glUseProgram(m_program);
}

GLuint Shader::CreateShader(const string& text, GLenum ShaderType)
{
	GLuint shader = glCreateShader(ShaderType);
	if (shader == 0)
		cout << "Shader creation failed.." << endl;

	const GLchar* a[1];
	a[0] = text.c_str();
	GLint alength[1];
	alength[0] = text.length();

	glShaderSource(shader, 1, a, alength);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Shader compilation failed..");
	return shader;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);
	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		cout << errorMessage << ": '" << error << "'" << endl;
	}
}



string Shader::LoadShader(const string& fileName)

{
	ifstream file;
	file.open((fileName).c_str());
	string output;
	string line;
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		cout << "Unable to load shader: " << fileName << endl;
	}
	return output;
}

Shader::~Shader()
{
	for (unsigned int i = 0; i < num_shaders; i++)
	{
		glDetachShader(m_program,m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}
	glDeleteProgram(m_program);
}
