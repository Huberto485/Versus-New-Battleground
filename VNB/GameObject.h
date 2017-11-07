#pragma once

#include "Game.h"

class GameObject
{

public:
	GameObject(const char* TextureSheet, SDL_Renderer* Ren, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int Xpos;
	int Ypos;

	SDL_Texture* ObjectTexture;
	SDL_Rect SrcRect, DestRect;
	SDL_Renderer* Renderer;

};