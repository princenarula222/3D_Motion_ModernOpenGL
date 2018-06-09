#include "Texture.h"
#include "stb_image.h"
#include<iostream>
#include<assert.h>

Texture::Texture(const string& filename)
{
	int width, height, num_components;
	unsigned char* imagedata = stbi_load(filename.c_str(), &width, &height, &num_components, 4);
	if (imagedata == NULL)
		cerr << "Image could not be loaded.." << endl;
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imagedata);
	stbi_image_free(imagedata);
}

void Texture::bind(unsigned int unit)
{
	assert(unit >= 0 && unit < 32);
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}


Texture::~Texture()
{
	glDeleteTextures(1, &m_texture);
}
