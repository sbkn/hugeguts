#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define FPS 60

//Main loop flag
bool quitGame = false;
//Event handler
SDL_Event event;

int main()
{
	std::cout << "Hello World!"
			  << "\n";
	;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *win = SDL_CreateWindow("HugeGuts", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr)
	{
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	std::string imagePath = "res/hello.bmp";
	SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
	if (bmp == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	int frames_drawn = 0;
	Uint32 frameStart = 0;

	/* GAME LOOP */
	while (!quitGame)
	{
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
				case SDL_QUIT:
					quitGame = true;
					break;
				default:
					break;
			}
		}

		SDL_RenderClear(ren);
		SDL_RenderCopy(ren, tex, NULL, NULL);

		SDL_Rect rect;
		rect.w = 25;
		rect.h = 50;
		rect.x = WINDOW_WIDTH / 2 - rect.w;
		rect.y = WINDOW_HEIGHT / 2 - rect.h;
		SDL_RenderDrawRect(ren, &rect);

		//Update the screen
		SDL_RenderPresent(ren);

		/*	HANDLE THE FPS:	*/
		frames_drawn++;
		/*	Sleep to keep the FPS as defined:	*/
		int frameHandlingMs = (SDL_GetTicks() - frameStart);
		if ((1000 / FPS) > frameHandlingMs)
		{
			SDL_Delay((1000 / FPS) - frameHandlingMs);
		}
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	std::cout << "Bye World!"
			  << "\n";

	return 0;
}
