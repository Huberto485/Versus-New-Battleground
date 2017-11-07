#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{

public:
	Game();
	~Game();

	void Init(const char* Title, int Xpos, int Ypos, int Width, int Height, bool Fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();

	bool Running()
	{
		return IsRunning;
	};

private:
	int cnt = 0;
	bool IsRunning;
	SDL_Window *Window;
	SDL_Renderer *Renderer;
};


