#pragma once
#include<glm/glm.hpp>
#include<GL/glew.h>
using namespace std;

class vertex {
public:
	vertex(glm::vec3& pos, glm::vec2& texCoord)
	{
		this->pos = pos;
		this->texCoord = texCoord;
	}
	glm::vec3 pos;
	glm::vec2 texCoord;
};
class mesh
{
public:
	mesh(vertex* vertices, unsigned int num_vertices);
	void draw();
	virtual ~mesh();
private:
	enum 
	{
		vb_position,texCoord_vb,
	    num_buffers
	};
	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[num_buffers];
	unsigned int m_count;
};

