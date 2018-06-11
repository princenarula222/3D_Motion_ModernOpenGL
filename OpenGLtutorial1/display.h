#pragma once
#include<string>
#include<SDL2/SDL.h>
using namespace std;
class display
{
public:
	display(int width, int height, const string& title);
	display();
	void Update();
	bool isclosed();
	virtual ~display();
private:
	SDL_Window* window;
	SDL_GLContext m;
	bool isClosed;
};

