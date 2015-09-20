#include "pong.h"

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
