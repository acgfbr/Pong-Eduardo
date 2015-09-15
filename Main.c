#include "elite.h"
//#include "elite.c"
char title[] = "Pong by Elite Game Dev - 21/09/2015";

SDL_Window* main_window = NULL;
SDL_Renderer* main_renderer = NULL;

void InitSDL2();
void DrawCenterLine();

void Exit();

typedef struct s_player
{
	SDL_Rect Player1,Player2;
}player_t;
void InitializePlayers(player_t *Game);
void DrawPlayers(player_t *Game);

int main(int argc, char* argv[])
{
	InitSDL2(); // Da partida no motor do sdl
	player_t *Game;
	Game = (player_t*)malloc(sizeof(player_t));
	InitializePlayers(Game);
	
	while(1)
	{
		SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255); // seta preto como plano de fundo.
		SDL_RenderClear(main_renderer ); // limpa o render [ janela atual ]
		DrawPlayers(Game);
		DrawCenterLine(); // desenha a linha central..
		SDL_Event event; // detecção de eventos sdl
		while(SDL_PollEvent(&event))
		{
				switch(event.key.keysym.sym) // detecção do teclado
				{
					case SDLK_w:
								if(Game->Player1.y<=0)
								{
									Game->Player1.y=10;
								}
								Game->Player1.y-=10;
								break;
					case SDLK_s:
								if(Game->Player1.y>=475)
								{
									Game->Player1.y=465;
								}
								Game->Player1.y+=10;
								break;
                    case SDLK_UP:
								if(Game->Player2.y<=0)
								{
									Game->Player2.y=10;
								}
								Game->Player2.y-=10;
								break;
					case SDLK_DOWN:
								if(Game->Player2.y>=475)
								{
									Game->Player2.y=465;
								}
								Game->Player2.y+=10;
								break;
                    default:
                        break;
				}
		}
		SDL_RenderPresent(main_renderer );
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
void InitializePlayers(player_t *Game)
{
	Game->Player1.x = 5;   /* */   Game->Player2.x = 765;   // inicialização dos retangulos..
	Game->Player1.y = 5;   /* */   Game->Player2.y = 470;   // inicialização dos retangulos..
	Game->Player1.w = 25;  /* */   Game->Player2.w = 25;    // inicialização dos retangulos..
	Game->Player1.h = 125; /* */   Game->Player2.h = 125;   // inicialização dos retangulos..
}
void DrawPlayers(player_t *Game)
{
		
		SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255); // seta branco a cor do retangulo que desenharei 
		SDL_RenderFillRect(main_renderer, &Game->Player1); // desenha um retangulo
		
		SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255); // seta branco a cor do retangulo que desenharei 
		SDL_RenderFillRect(main_renderer, &Game->Player2); // desenha um retangulo
	
}
void Exit()
{
	
	SDL_DestroyWindow(main_window);
	SDL_DestroyRenderer(main_renderer);
	SDL_Quit();

}