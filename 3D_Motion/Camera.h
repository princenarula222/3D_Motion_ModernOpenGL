#pragma once
#include<glm/glm.hpp>
#include<glm/gtx/transform.hpp>

class Camera
{
public:

	glm::vec3 m_position;
	Camera(glm::vec3& pos, float fav, float ar,float near, float far)
	{
		perspective = glm::perspective(fav, ar, near, far);
		m_position = pos;
		m_up = glm::vec3(0, 1, 0);
		m_center = glm::vec3(0, 0, 0);
	}

	glm::mat4 getView() 
	{
		glm::mat4 view = glm::lookAt(m_position, m_center, m_up);

		return perspective*view;
	}

	virtual ~Camera()
	{
	}
private:
	glm::mat4 perspective;
	glm::vec3 m_up;
	glm::vec3 m_center;
};

