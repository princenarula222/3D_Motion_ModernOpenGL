#include "mesh.h"
#include<vector>

mesh::mesh(vertex* vertices, unsigned int num_vertices)
{
	m_count = num_vertices;
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	vector<glm::vec3> positions;
	vector<glm::vec2> texCoords;

	positions.reserve(num_vertices);
	texCoords.reserve(num_vertices);

	for (unsigned int i = 0; i < num_vertices; i++)
	{
		positions.push_back(vertices[i].pos);
		texCoords.push_back(vertices[i].texCoord);
	}

	glGenBuffers(num_buffers, m_vertexArrayBuffers);
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[vb_position]);
    glBufferData(GL_ARRAY_BUFFER, num_vertices*sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[texCoord_vb]);
	glBufferData(GL_ARRAY_BUFFER, num_vertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindVertexArray(0);
}

void mesh::draw()
{
	glBindVertexArray(m_vertexArrayObject);

	glDrawArrays(GL_TRIANGLES, 0, m_count);

	glBindVertexArray(0);

}


mesh::~mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}
