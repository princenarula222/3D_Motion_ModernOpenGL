#include "display.h"
#include<iostream>
#include<GL/glew.h>
using namespace std;

display::display(int width, int height, const string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m = SDL_GL_CreateContext(window);
	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		cout << "\n Failed to initialize glew.." << endl;
	}
	isClosed = false;
}
void display::Update()
{
	SDL_GL_SwapWindow(window);
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			isClosed = true;
	}
}
bool display::isclosed()
{
	return isClosed;
}

display::~display()
{
	SDL_GL_DeleteContext(m);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
