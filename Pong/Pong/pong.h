#ifndef PONG_H_
#define PONG_H_
#include "elite.h"

const char *title;
SDL_Window *main_window;
SDL_Renderer *main_renderer;

typedef struct s_player
{
    SDL_Rect Player1, Player2;
    SDL_Rect Bolinha;
    float multiplierX, multiplierY;

}player_t;

void InitSDL2();
void DrawCenterLine();
void Exit();
void InitializePlayers(player_t *Game);
void DrawPlayers(player_t *Game);
void funcaoBolinha(player_t *Game);
void CheckCollisionLeft(player_t *Game);
void CheckCollisionRight(player_t *Game);
void CheckCollisionTop(player_t *Game);
void CheckCollisionBottom(player_t *Game);

#endif
