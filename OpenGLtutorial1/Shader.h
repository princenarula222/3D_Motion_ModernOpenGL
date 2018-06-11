#pragma once
#include<string>
#include<GL/glew.h>
#include "Transform.h"
#include "Camera.h"
using namespace std;
class Shader
{
public:
	Shader(const string& filename);
	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);
	static string LoadShader(const string& fileName);
	static GLuint CreateShader(const string& text, GLenum ShaderType);
	void bind();
	void update(Transform& transform, Camera& cam);
	virtual ~Shader();
private:
	enum {
		m_uniform,
	num_uniforms
	};
	const static unsigned int num_shaders=2;
	GLuint m_program;
	GLuint m_shaders[num_shaders];
	GLuint m_uniforms[num_uniforms];
};

