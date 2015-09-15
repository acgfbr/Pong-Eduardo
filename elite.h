#ifndef ELITE_H_
#define ELITE_H_

/******** Includes e diretivas na Plataforma Windows ********/
#ifdef _WIN32

/* BIBLIOTECAS PADRÃO... */

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

/* BIBLIOTECAS SDL */
#include <SDL.h>
#include <SDL_mixer.h>
#define CLEAR "cls"


/******** Includes e diretivas na Plataforma Unix ********/
#else

/* BIBLIOTECAS PADRÃO...*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

/* BIBLIOTECAS SDL */
#include <SDL2/SDL.h>            /* SDL */
#include <SDL2/SDL_video.h>      /* SDL */
#include <SDL2/SDL_image.h>      /* SDL_Image */
#include <SDL2/SDL_ttf.h>        /* SDL_TTF */
#include <SDL2/SDL_mixer.h>      /* SDL_Mixer */
#include <SDL2/SDL2_rotozoom.h>  /* SDL_GFX */
#include <SDL2/SDL2_framerate.h> /* SDL_GFX */


#define CLEAR "clear"

#endif

/******** Includes e diretivas para ambas as plataformas ********/

/* BIBLIOTECAS ELITE */
/*#include"elite.c"*/

#define main_window_x 800
#define main_window_y 600

#endif
