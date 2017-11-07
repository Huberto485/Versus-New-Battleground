#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* Player;
GameObject* Enemy;

Game::Game()
{}
Game::~Game()
{}

//Function that creates a game window where some of the other functions will be executed
void Game::Init(const char *Title, int Xpos, int Ypos, int Width, int Height, bool Fullscreen)
{
	int Flags = 0;

	if (Fullscreen)
	{
		Flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		Window = SDL_CreateWindow(Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, Fullscreen);
		Renderer = SDL_CreateRenderer(Window, -1, 0);
		if (Renderer)
		{
			SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
		}

		IsRunning = true;
	}

	//All the game objects that are in the game will be created in this section
	Player = new GameObject("Assets/player.png", Renderer, 0, 0);
	Enemy = new GameObject("Assets/player.png", Renderer, 70, 0);
}

//If an even occurs such as error or the window quits, this will show appropriate text message
void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		IsRunning = false;
		break;

	default:
		break;
	}
}

//Updates the parameters of the objects in the game window
void Game::Update()
{
	Player->Update();
	Enemy->Update();
}

//Renders the pixels of the gifs and images
void Game::Render()
{
	SDL_RenderClear(Renderer);
	Player->Render();
	Enemy->Render();
	SDL_RenderPresent(Renderer);
}

//Clears the window of any textues(images and gifs) and then quits
void Game::Clean()
{
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}