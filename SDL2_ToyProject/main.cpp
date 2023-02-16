#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

#include "RenderWindow.h"
#include "Entity.h"
#include "Utils.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_image.lib")

using namespace std;


int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		cout << "SDL_Init has failed. SDL_ERROR : " << SDL_GetError() << endl;
	}

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "IMG_init has failed. Error: " << SDL_GetError() << endl;

	RenderWindow window("GAME v1.0", 1280, 720);

	SDL_Texture* girlTexture = window.loadTexture("Resource/pixel_lady_01.png");

	Entity platform0(500, 500, girlTexture);
	Entity platform1(0, 0, girlTexture);

	bool gameRunning = true;

	SDL_Event event;



	while (gameRunning)
	{
		Uint64 start = SDL_GetPerformanceCounter();

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}


		window.clear();
		window.render(platform0);
		window.render(platform1);

		window.display();

		Uint64 end = SDL_GetPerformanceCounter();

		float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
		cout << "Current FPS: " << to_string(1.0f / elapsed) << endl;
	}

	window.cleanUp();
	SDL_Quit();
	return 0;
}