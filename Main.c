#include "elite.h"
//#include "elite.c"
char title[] = "Pong by Elite Game Dev - 21/09/2015";

SDL_Window* main_window = NULL;
SDL_Renderer* main_renderer = NULL;

void InitSDL2();
void DrawCenterLine();
void Exit();

int main(int argc, char* argv[])
{
	InitSDL2(); // Da partida no motor do sdl

	SDL_Rect Player1,Player2;
	Player1.x = 5;   /* */   Player2.x = 765;   // inicialização dos retangulos..
	Player1.y = 5;   /* */   Player2.y = 470;   // inicialização dos retangulos..
	Player1.w = 25;  /* */   Player2.w = 25;    // inicialização dos retangulos..
	Player1.h = 125; /* */   Player2.h = 125;   // inicialização dos retangulos..

	while(1)
	{
		SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255); // seta preto como plano de fundo.
		SDL_RenderClear(main_renderer ); // limpa o render [ janela atual ]
		DrawCenterLine(); // desenha a linha central..
		
		
		SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255); // seta branco a cor do retangulo que desenharei 
		SDL_RenderFillRect(main_renderer, &Player1); // desenha um retangulo
		
		SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255); // seta branco a cor do retangulo que desenharei 
		SDL_RenderFillRect(main_renderer, &Player2); // desenha um retangulo
		
		
		SDL_Event event; // detecção de eventos sdl
		while(SDL_PollEvent(&event))
		{
				switch(event.key.keysym.sym) // detecção do teclado
				{
					case SDLK_w:
								Player1.y-=10;
								break;
					case SDLK_s:
								Player1.y+=10;
								break;
                    case SDLK_UP:
								Player2.y-=10;
								break;
					case SDLK_DOWN:
								Player2.y+=10;
								break;
                    default:
                        break;
				}
		}


		SDL_RenderPresent(main_renderer );
		//SDL_Delay(100);
	}
	Exit();
}
void InitSDL2()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	main_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, main_window_x, main_window_y, SDL_WINDOW_SHOWN);
	if (main_window != NULL)
	{
		main_renderer = SDL_CreateRenderer(main_window, -1, 0);
	}
}
void DrawCenterLine()
{
		int i=0;
		for (i = 0; i < 600; i++)
		{
			i+=10;
			SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255);
			SDL_RenderDrawPoint(main_renderer, 390, i);
		}
}
void Exit()
{
	
	SDL_DestroyWindow(main_window);
	SDL_DestroyRenderer(main_renderer);
	SDL_Quit();

}