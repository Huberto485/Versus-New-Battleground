//This set of functions creates game objects that will be displayed and updated within the window
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* TextureSheet, SDL_Renderer* Ren, int x, int y)
{
	Renderer = Ren;
	ObjectTexture = TextureManager::LoadTexture(TextureSheet, Ren);

	Xpos = x;
	Ypos = y;
}

void GameObject::Update()
{
	Xpos;
	Ypos;

	SrcRect.h = 64;
	SrcRect.w = 64;
	SrcRect.x = 0;
	SrcRect.y = 0;
	
	DestRect.x = Xpos;
	DestRect.y = Ypos;
	DestRect.w = SrcRect.w * 2;
	DestRect.h = SrcRect.h * 2;
}

//Requires and input pathway and then outputs the rendered copy of an image onto the window
void GameObject::Render()
{
	SDL_RenderCopy(Renderer, ObjectTexture, &SrcRect, &DestRect);
}