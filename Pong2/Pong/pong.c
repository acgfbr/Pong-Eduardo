#include "pong.h"



void DrawCenterLine(colors_t* list)
{
    int i = 0;

    for (i = 0; i < 600; i++)
    {
        i += 10;
        SDL_SetRenderDrawColor(main_renderer, list->R, list->G, list->B, 255);
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

    /* Score Player1 */                   /* Score Player2 */
    Game->Score_Player1.x = 320; /* */  Game->Score_Player2.x = 395;
    Game->Score_Player1.y = 5;   /* */  Game->Score_Player2.y = 5;
    Game->Score_Player1.w = 59;  /* */  Game->Score_Player2.w = 59;
    Game->Score_Player1.h = 49;  /* */  Game->Score_Player2.h = 49;
    Game->PointsPlayer1 = 0;     /* */  Game->PointsPlayer2 = 0;
}

void DrawPlayers(player_t *Game, colors_t* list)
{


    SDL_SetRenderDrawColor(main_renderer, list->R, list->G, list->B, 255);
    SDL_RenderFillRect(main_renderer, &Game->Player1); // desenha um retangulo

    SDL_SetRenderDrawColor(main_renderer, list->R, list->G, list->B, 255);
    SDL_RenderFillRect(main_renderer, &Game->Player2); // desenha um retangulo

    SDL_SetRenderDrawColor(main_renderer, list->R, list->G, list->B, 255);
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
    int Delay=0;

    CheckCollisionLeft(Game);
    CheckCollisionRight(Game);
    CheckCollisionTop(Game);
    CheckCollisionBottom(Game);
    Game->Bolinha.x += Game->multiplierX;
    Game->Bolinha.y += Game->multiplierY;

    while(Delay < 1999999)
        Delay++;
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
            Game->multiplierY = Game->multiplierY *-1;
            printf("DEFENDEU 1 \n");
        }
        else

        {
            printf("GOL \n");
			PointRegisterSound();
            Game->PointsPlayer2++;
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
            Game->multiplierY = Game->multiplierY *-1;
            printf("DEFENDEU 2 \n");
        }

        else
        {
            printf("GOL2 \n");
			PointRegisterSound();
            Game->PointsPlayer1++;
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

colors_t *Create_Color(colors_t* list, string name, int Red, int Green, int Blue)
{
    colors_t *Aux = (colors_t*) malloc(sizeof(colors_t));

    if(Aux == NULL)
    {
        printf("Malloc Error - Create_Color function.\n");
        return NULL;
    }
    else
    {
        Aux->R = Red;
        Aux->G = Green;
        Aux->B = Blue;
        Aux->color_name = name;
        Aux->next_color = list;

        return Aux;
    }
}

colors_t *Get_Color(colors_t *list, string name)
{
    if(list == NULL)
    {
        printf("List does not exist\n");
        return NULL;
    }
    else
    {
        colors_t *aux = list;

        while(aux != NULL)
        {
             if(!strcmp(aux->color_name, name))
                 return aux;

             else
                aux = aux->next_color;
        }
    }

    return NULL;
}

colors_t* Create_List(colors_t* list)
{
    colors_t *ColorList = (colors_t*) malloc(sizeof(colors_t));

    ColorList->next_color = list;

    ColorList = Create_Color(ColorList, "Red", 255, 0, 0);
    ColorList = Create_Color(ColorList, "OrangeRed", 255, 69, 0);
    ColorList = Create_Color(ColorList, "Firebrick", 178, 34, 34);
    ColorList = Create_Color(ColorList, "Chocolate", 210, 105, 30);
    ColorList = Create_Color(ColorList, "Marrom Filtro de barro", 165,42,42);
    ColorList = Create_Color(ColorList, "Gold", 255, 215, 0);
    ColorList = Create_Color(ColorList, "NightGoldenrod", 238, 221, 130);
    ColorList = Create_Color(ColorList, "Goldenrod", 218, 165, 32);
    ColorList = Create_Color(ColorList, "DarkGoldenrod", 184, 134, 11);
    ColorList = Create_Color(ColorList, "RoyalBlue", 72, 118, 255);
    ColorList = Create_Color(ColorList, "SkyBlue", 135, 206, 255);
    ColorList = Create_Color(ColorList, "LightSkyBlue", 176, 226, 255);
    ColorList = Create_Color(ColorList, "DeepSkyBlue", 0, 191, 255);
    ColorList = Create_Color(ColorList, "Green", 0, 255, 0);
    ColorList = Create_Color(ColorList, "MediumSpringGreen", 0, 250, 154);
    ColorList = Create_Color(ColorList, "ForestGreen", 34, 139, 34);
    ColorList = Create_Color(ColorList, "LimeGreen", 50, 205, 50);
    ColorList = Create_Color(ColorList, "Pink", 255, 192, 203);
    ColorList = Create_Color(ColorList, "LightPink", 255, 182, 193);
    ColorList = Create_Color(ColorList, "DeepPink", 255, 20, 147);
    ColorList = Create_Color(ColorList, "HotPink", 255, 105, 180);
    ColorList = Create_Color(ColorList, "Magenta", 255, 0, 255);
    ColorList = Create_Color(ColorList, "Orchid", 218, 112, 214);
    ColorList = Create_Color(ColorList, "MediumOrchid", 186, 85, 211);
    ColorList = Create_Color(ColorList, "DarkOrchid", 153, 50, 204);
    ColorList = Create_Color(ColorList, "Black", 0, 0, 0);
    ColorList = Create_Color(ColorList, "White", 255, 255, 255);

    return ColorList;
}

void Free_List(colors_t *list)
{
    colors_t *aux, *next;

    aux = list;

    while(aux != NULL)
    {
        next = aux->next_color;
        free(aux);
        aux = next;
    }

}

void Init_Score()
{
    Points[0] = IMG_LoadTexture(main_renderer, "Number_0.bmp");
    Points[1] = IMG_LoadTexture(main_renderer,"Number_1.bmp");
    Points[2] = IMG_LoadTexture(main_renderer,"Number_2.bmp");
    Points[3] = IMG_LoadTexture(main_renderer,"Number_3.bmp");
    Points[4] = IMG_LoadTexture(main_renderer,"Number_4.bmp");
    Points[5] = IMG_LoadTexture(main_renderer,"Number_5.bmp");
    Points[6] = IMG_LoadTexture(main_renderer,"Number_6.bmp");
    Points[7] = IMG_LoadTexture(main_renderer,"Number_7.bmp");
    Points[8] = IMG_LoadTexture(main_renderer,"Number_8.bmp");
    Points[9] = IMG_LoadTexture(main_renderer,"Number_9.bmp");
    Points[10] = IMG_LoadTexture(main_renderer,"Number_10.bmp");
}

void DrawScore(player_t *Game)
{
    SDL_RenderCopy(main_renderer, Points[Game->PointsPlayer1], NULL, &Game->Score_Player1);
    SDL_RenderCopy(main_renderer, Points[Game->PointsPlayer2], NULL, &Game->Score_Player2);
}


//void PlaySound()
//{
//	Mix_Music *themeSong = Mix_LoadMUS("imperialmarch.wav");
//	Mix_PlayMusic(themeSong, 0);
//}

void PointRegisterSound()
{
	Mix_Music *pointSong = Mix_LoadMUS("mk-soul.wav");
	Mix_PlayMusic(pointSong, 0);
}

void Play()
{
	player_t *Game;
	Game = (player_t*)malloc(sizeof(player_t));
	InitializePlayers(Game);
	Init_Score();
	colors_t *Pallet = NULL, *ColorLine = NULL, *ColorGame = NULL, *Background = NULL;

	Pallet = Create_List(Pallet);
	ColorLine = Get_Color(Pallet, "Red");
	ColorGame = Get_Color(Pallet, "Gold");
	Background = Get_Color(Pallet, "Black");

	//PlaySound();

	while (1)
	{
		SDL_SetRenderDrawColor(main_renderer, Background->R, Background->G, Background->B, 255); // seta preto como plano de fundo.
		SDL_RenderClear(main_renderer); // limpa o render [ janela atual ]
		DrawPlayers(Game, ColorGame);
		DrawCenterLine(ColorLine); // desenha a linha central..
		DrawScore(Game);
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

		//Check PLayer Points
		if (Game->PointsPlayer1 == 10)
		{
			break;
		}


	}
	Free_List(Pallet);
}
