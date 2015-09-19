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
	SDL_Rect Player1, Player2;
	SDL_Rect Bolinha;
	float multiplierX, multiplierY;

}player_t;
void InitializePlayers(player_t *Game);
void DrawPlayers(player_t *Game);
void funcaoBolinha(player_t *Game);
void CheckCollisionLeft(player_t *Game);
void CheckCollisionRight(player_t *Game);
void CheckCollisionTop(player_t *Game);
void CheckCollisionBottom(player_t *Game);

int main(int argc, char* argv[])
{
	InitSDL2(); // Da partida no motor do sdl
	player_t *Game;
	Game = (player_t*)malloc(sizeof(player_t));
	InitializePlayers(Game);
	

	while (1)
	{
		SDL_SetRenderDrawColor(main_renderer, 0, 0, 0, 255); // seta preto como plano de fundo.
		SDL_RenderClear(main_renderer); // limpa o render [ janela atual ]
		DrawPlayers(Game);
		DrawCenterLine(); // desenha a linha central..
		SDL_Event event; // detecção de eventos sdl
		while (SDL_PollEvent(&event))
		{
			switch (event.key.keysym.sym) // detecção do teclado
			{
			case SDLK_w:
				if (Game->Player1.y <= 0)
				{
					Game->Player1.y = 10;
				}
				Game->Player1.y -= 10;
				break;
			case SDLK_s:
				if (Game->Player1.y >= 475)
				{
					Game->Player1.y = 465;
				}
				Game->Player1.y += 10;
				break;
			case SDLK_UP:
				if (Game->Player2.y <= 0)
				{
					Game->Player2.y = 10;
				}
				Game->Player2.y -= 10;
				break;
			case SDLK_DOWN:
				if (Game->Player2.y >= 475)
				{
					Game->Player2.y = 465;
				}
				Game->Player2.y += 10;
				break;
			default:
				break;
			}
		}

		funcaoBolinha(Game);

		//chama aqui a funcao de checa colisao da bolinha e inverte o lado.
		SDL_RenderPresent(main_renderer);
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
	int i = 0;
	for (i = 0; i < 600; i++)
	{
		i += 10;
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

	//Bolinha
	Game->Bolinha.h = 15;
	Game->Bolinha.w = 15;
	Game->Bolinha.x = 300;
	Game->Bolinha.y = 400;

	Game->multiplierX = 1;
	Game->multiplierY = 1;

}
void DrawPlayers(player_t *Game)
{

	SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255); // seta branco a cor do retangulo que desenharei 
	SDL_RenderFillRect(main_renderer, &Game->Player1); // desenha um retangulo

	SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255); // seta branco a cor do retangulo que desenharei 
	SDL_RenderFillRect(main_renderer, &Game->Player2); // desenha um retangulo4

	SDL_SetRenderDrawColor(main_renderer, 255, 255, 255, 255); // seta branco a cor do retangulo que desenharei
	SDL_RenderFillRect(main_renderer, &Game->Bolinha); // desenha um retangulo

}
void Exit()
{

	SDL_DestroyWindow(main_window);
	SDL_DestroyRenderer(main_renderer);
	SDL_Quit();

}

void funcaoBolinha(player_t *Game)
{

	CheckCollisionLeft(Game);
	CheckCollisionRight(Game);
	CheckCollisionTop(Game);
	CheckCollisionBottom(Game);
	Game->Bolinha.x += Game->multiplierX;
	Game->Bolinha.y += Game->multiplierY;
}


void CheckCollisionLeft(player_t *Game)
{
	int bLeft = Game->Bolinha.x;
	if (bLeft <= 5)
	{
		int topBola = Game->Bolinha.y;
		int bottomBola = Game->Bolinha.y + Game->Bolinha.h;

		printf("TOP BOLA %d \n", topBola);
		printf("BOT BOLA %d \n", bottomBola);


		int player1Top = Game->Player1.y;
		int player1Bottom = Game->Player1.y + Game->Player1.h;

		printf("TOP P %d \n", player1Top);
		printf("BOT P %d \n", player1Bottom);


		if (bottomBola >= player1Top && topBola <= player1Bottom)
		{
			Game->multiplierX = Game->multiplierX * -1;
			printf("DEFENDEU 1 \n");
		}
		else
		{
			printf("GOL \n");
			Game->multiplierX = Game->multiplierX * -1;
		}
	}

}

void CheckCollisionRight(player_t *Game)
{
	//printf("TA NA CHECK COLISAO DIREITA");
	int bRight = Game->Bolinha.x + Game->Bolinha.w;
	if (bRight >= 795)
	{
		int topBola = Game->Bolinha.y;
		int bottomBola = Game->Bolinha.y + Game->Bolinha.h;

		printf("TOP BOLA 2 %d \n", topBola);
		printf("BOT BOLA 2 %d \n", bottomBola);


		int player2Top = Game->Player2.y;
		int player2Bottom = Game->Player2.y + Game->Player2.h;

		printf("TOP P2 %d \n", player2Top);
		printf("BOT P2 %d \n", player2Bottom);


		if (bottomBola >= player2Top && topBola <= player2Bottom)
		{
			Game->multiplierX = Game->multiplierX * -1;
			printf("DEFENDEU 2 \n");
		}
		else
		{
			printf("GOL2 \n");
			Game->multiplierX = Game->multiplierX * -1;
		}
	}
}


void CheckCollisionTop(player_t *Game)
{
	//printf("TA NA CHECK COLISAO DIREITA");
	int bTop = Game->Bolinha.y;
	if (bTop <= 5)
	{
		Game->multiplierY = Game->multiplierY * -1;
		//printf("%f \n", Game->multiplierX);
	}

}


void CheckCollisionBottom(player_t *Game)
{
	//printf("TA NA CHECK COLISAO DIREITA");
	int bBottom = Game->Bolinha.y + Game->Bolinha.h;
	if (bBottom >= 595)
	{
		Game->multiplierY = Game->multiplierY * -1;
		//printf("%f \n", Game->multiplierX);
	}

}

