#pragma once
#include<string>
#include<GL/glew.h>
using namespace std;
class Texture
{
public:
	Texture(const string& filename);
	void bind(unsigned int unit);
	virtual ~Texture();
private:
	GLuint m_texture;

};

