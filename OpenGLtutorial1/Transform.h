#pragma once
#include<glm/glm.hpp>
#include<glm/gtx/transform.hpp>

class Transform
{
public:

	Transform(glm::vec3& pos = glm::vec3(0), glm::vec3& rot = glm::vec3(), glm::vec3& scal = glm::vec3( 1.0,1.0,1.0 )) :
	m_pos(pos),
	m_rot(rot),
	m_scal(scal){}

	inline glm::mat4 getModel()
	{
		glm::mat4 posMat = glm::translate(m_pos);
		glm::mat4 rotMatX = glm::rotate(m_rot.x,glm::vec3(1.0,0.0,0.0));
		glm::mat4 rotMatY = glm::rotate(m_rot.y, glm::vec3(0.0, 1.0, 0.0));
		glm::mat4 rotMatZ = glm::rotate(m_rot.z, glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 scalMat = glm::scale(m_scal);

		glm::mat4 rotMat = rotMatZ * rotMatY * rotMatX;

		return scalMat * rotMat * posMat;
	}
	inline void setPos(glm::vec3& pos) { m_pos = pos; }
	inline void setRot(glm::vec3& rot) { m_rot = rot; }
	inline void setScal(glm::vec3& scal) { m_scal = scal; }
	inline glm::vec3& getPos() {	return m_pos; }
	inline glm::vec3& getRot() { return m_rot; }
	inline glm::vec3& getScal() { return m_scal; }

	virtual ~Transform()
	{

	}
private:
	glm::vec3 m_pos;
	glm::vec3 m_rot;
	glm::vec3 m_scal;
};

