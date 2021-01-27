#include "SDLX.h"

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
      Uint8 *target_pixel = (Uint8 *)surface->pixels + y * surface->pitch + x * 4;
      *(Uint32 *)target_pixel = pixel;
}

int	RGBA_to_int(int r, int g, int b, int a)
{
	int result;

    result = (r << 24) + (g << 16) + (b << 8) + (a << 0);
	return result;
}

void Int_to_RGBA(int color, int *r , int *g, int *b, int *a)
{
	*r = (color >> 26) & 0xFF;
	*g = (color >> 16) & 0xFF;
	*b = (color >>  8) & 0xFF;
	*a = (color >>  0) & 0xFF;
}