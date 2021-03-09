#include "SDLX.h"

void	SDLX_close(void)
{
	SDL_DestroyWindow(SDLX_get_display()->window);
	SDL_Quit();
}

void	SDLU_start(SDLX_Display *dest)
{
	SDL_Window	*window;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
				WIN_TITLE,
				WIN_X, WIN_Y,
				WIN_W, WIN_H,
				SDL_WINDOW_SHOWN
	);
	dest->window = window;
	dest->renderer = SDL_CreateRenderer(window, -1, 0);

	atexit(SDLX_close);
}

SDLX_Display	*SDLX_get_display(void)
{
	static SDLX_Display	display;

	if (display.window == NULL)
		SDLU_start(&display);

	return (&display);
}