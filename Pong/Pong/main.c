#include "pong.h"

void Play();

int main(int argc, char* argv[])
{
	// START DO SDL #####################################
	const string title = "Pong by Elite Game Dev - 21/09/2015";
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
	SDL_Window * main_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, main_window_x, main_window_y, SDL_WINDOW_SHOWN);

	if (main_window != NULL)
	{
		main_renderer = SDL_CreateRenderer(main_window, -1, 0);
	}
	// START DO SDL #####################################

	// LOAD IMAGENS
	menu = SDL_LoadBMP("menu.bmp");
	play = SDL_LoadBMP("Play.bmp");
	// LOAD IMAGENS
	int Menu = 1;

	while (Menu)
	{
		SDL_Event event;
		tela = SDL_GetWindowSurface(main_window);
		while (SDL_PollEvent(&event))
		{

			SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255); // seta preto como plano de fundo.
			SDL_RenderClear(main_renderer); // limpa o render [ janela atual ]

			if ((event.button.x >= 601 && event.button.y >= 69) && (event.button.x <= 688 && event.button.y <= 94)) // START
			{
				SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);
				SDL_BlitSurface(play, NULL, tela, NULL);
				SDL_UpdateWindowSurface(main_window);
			}
			else if ((event.button.x >= 601 && event.button.y >= 149) && (event.button.x <= 679 && event.button.y <= 174)) // EXIT
			{

			}
			else
			{
				SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255);
				SDL_BlitSurface(menu, NULL, tela, NULL);
				SDL_UpdateWindowSurface(main_window);
			}


			switch (event.type)
			{


			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT || event.button.button == SDL_BUTTON_RIGHT)
				{
					
					if ((event.button.x >= 601 && event.button.y >= 69) && (event.button.x <= 688 && event.button.y <= 94)) // START
					{
						Menu = 0;
						Play();
					}
					else if ((event.button.x >= 601 && event.button.y >= 149) && (event.button.x <= 679 && event.button.y <= 174)) // EXIT
					{
						Exit();
					}
				}
				break;
			}
		}
	}
	
    Exit();
}
