#ifndef PONG_H_
#define PONG_H_
#include "elite.h"

typedef enum {FALSE, TRUE} bool;
typedef char* string;
const string title;
SDL_Window *main_window;
SDL_Renderer *main_renderer;
SDL_Texture *Points[11];


typedef struct s_player
{
    SDL_Rect Player1, Player2;
    SDL_Rect Bolinha;
    SDL_Rect Score_Player1, Score_Player2;
    float multiplierX, multiplierY;
    int PointsPlayer1, PointsPlayer2;

}player_t;

typedef struct s_colors
{
    int R,G,B;
    string color_name;
    struct s_colors *next_color;
}
colors_t;

void InitSDL2();
void DrawCenterLine(colors_t* list);
void Exit();
void InitializePlayers(player_t *Game);
void DrawPlayers(player_t *Game, colors_t* list);
void funcaoBolinha(player_t *Game);
void CheckCollisionLeft(player_t *Game);
void CheckCollisionRight(player_t *Game);
void CheckCollisionTop(player_t *Game);
void CheckCollisionBottom(player_t *Game);
void Free_List(colors_t *list);
void Init_Score();
void DrawScore(player_t *Game);
colors_t *Create_Color(colors_t* list, string name, int Red, int Green, int Blue);
colors_t *Get_Color(colors_t *list, string name);
colors_t* Create_List(colors_t *list);

#endif
