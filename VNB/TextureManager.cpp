//This function creates a temporary box which can hold a graphical texture of an object
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* Texture, SDL_Renderer* Ren)
{
	SDL_Surface* TemporarySurface = IMG_Load(Texture);
	SDL_Texture* Tex = SDL_CreateTextureFromSurface(Ren, TemporarySurface);
	SDL_FreeSurface(TemporarySurface);

	return Tex;
}