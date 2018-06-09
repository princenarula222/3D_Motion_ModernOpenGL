#include<iostream>
#include "display.h"
#include<GL/glew.h>
#include "Shader.h"
#include "mesh.h"
#include "Texture.h"
#include "Transform.h"

#define ar 800.0/600
using namespace std;

int main(int argc, char* argv[])
{
	display Display(800, 600, "Hello World");
	vertex vertices[] = { vertex(glm::vec3(-0.5,-0.5,0),glm::vec2(0,1)), 
		vertex(glm::vec3(0.5,-0.5,0),glm::vec2(1,1)),
		vertex(glm::vec3(0,0.5,0),glm::vec2(0.5,0))
	};
	mesh m(vertices, 3);
	Shader shader("./res/basicShader");
	Texture texture("./res/sherlock.jpg");
	Transform transform;
	Camera cam(glm::vec3(0, 0, -8), (float)120.0, ar, 1.0, 1000);
	float counter = -1.5;
	while (!Display.isclosed())
	{
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		cam.m_position = glm::vec3(0, 0, -3+sin(counter));
		counter += 0.0005;
		shader.bind();
		texture.bind(0);
		shader.update(transform,cam);
		m.draw();
		Display.Update();
	}
	return 0;
}