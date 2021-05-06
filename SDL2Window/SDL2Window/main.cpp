#include <SDL.h>
#include <iostream>


int main(int argc, char *argv[])//SDL2 requires these parameters
{
	//Initialize window, surface for window, and surface for image
	SDL_Window *window = nullptr;
	SDL_Surface* windowSurface = nullptr;
	SDL_Surface* imageSurface = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)//Check if Video cannot be initialized
		std::cout << "Video Initialization Error: " << SDL_GetError() << std::endl;
	else
	{
		//Define window
		window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 477, 403, SDL_WINDOW_SHOWN);

		//Create isRunning bool check and event variable
		bool isRunning = true;
		SDL_Event ev;

		if (window == NULL)//Check if window wasn't created
			std::cout << "Window Creation Error: " << SDL_GetError() << std::endl;
		else
		{
			//Window Created
			windowSurface = SDL_GetWindowSurface(window);
			imageSurface = SDL_LoadBMP("image.bmp");

			if (imageSurface == NULL)//Check if Image could not be loaded
				std::cout << "Image Loading Error: " << SDL_GetError() << std::endl;
			else
			{
				while (isRunning)
				{
					while (SDL_PollEvent(&ev) != 0)
					{
						if (ev.type == SDL_QUIT)
							isRunning = false;
					}
					SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
					SDL_UpdateWindowSurface(window);
				}
				
			}
		}
	}

	//Free memory
	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	windowSurface = nullptr;
	SDL_Quit();

	return 0;
}