#ifndef SDLX_H
#define SDLX_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDLX_config.h"

typedef struct
{
	SDL_Renderer *renderer;
	SDL_Window *window;
} SDLX_Display;

SDLX_Display *SDLX_get_display(void);

void SDLX_Update(void);

void SDLX_SetPixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
int RGBA_to_int(int r, int g, int b, int a);
void Int_to_RGBA(int color, int *r, int *g, int *b, int *a);



#endif