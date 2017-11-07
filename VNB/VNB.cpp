//Game main where the functions are executed
#include <SDL.h>
#include "Game.h"

/*Lower case "game" is the object, capital case "Game" is the class 
that will have functions being executed*/
Game *game = nullptr;

int main(int argc, char *argv[])
{
	const int FrameRate = 60;
	const int FrameDelay = 1000 / FrameRate;

	Uint32 FrameStart;
	int FrameTime;

	game = new Game();

	game->Init("VNB", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	//Thil loop will update the changes to the parameters of these functions
	while(game->Running()) 
	{
		FrameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		FrameTime = SDL_GetTicks() - FrameStart;

		if (FrameDelay > FrameTime);
	}

	//Clears the window of the application -> usable later on after the game needs to be loaded
	game->Clean();

	return 0;
}
