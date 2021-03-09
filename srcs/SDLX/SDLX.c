#include "SDLX.h"
#include "RayMarch.h"

void SDLX_InputLoop(void)
{
	SDL_Event	event;
	Context		*ctx;
	const Uint8	*keystate;
	int x;
	int y;
	

	ctx = get_context();
	keystate = SDL_GetKeyboardState(NULL);

    if(keystate[SDL_SCANCODE_W])
		ctx->cam.position.z += 6;
    if(keystate[SDL_SCANCODE_S])
		ctx->cam.position.z -= 6;
    if(keystate[SDL_SCANCODE_D])
		ctx->cam.position.x += 6;
    if(keystate[SDL_SCANCODE_A])
		ctx->cam.position.x -= 6;
    if(keystate[SDL_SCANCODE_SPACE])
		ctx->cam.position.y += 6;
    if(keystate[SDL_SCANCODE_X])
		ctx->cam.position.y -= 6;

    if(keystate[SDL_SCANCODE_LEFT])
		ctx->cam.x_angle -= 3;
    if(keystate[SDL_SCANCODE_RIGHT])
		ctx->cam.x_angle += 3;
    if(keystate[SDL_SCANCODE_UP])
		ctx->cam.y_angle += 3;
    if(keystate[SDL_SCANCODE_DOWN])
		ctx->cam.y_angle -= 3;
	
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
		SDL_GetMouseState(&x, &y);
	}
}

void draline(void)
{
	int x, y;
	SDLX_Display *display;

	display = SDLX_get_display();
	y = 0 ;
	SDL_SetRenderDrawColor(display->renderer, 0, 255, 0, 255);
	while ( y < 20)
	{
		x = 0;
		while ( x < 20)
		{
			SDL_RenderDrawLine(display->renderer, (WIN_H / 20) * x, 0, (WIN_H / 20) * x, WIN_H);
			x++;
		}
		SDL_RenderDrawLine(display->renderer, 0, (WIN_H / 20) * y, WIN_W,(WIN_H / 20) * y);
		y++;
	}
	SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255);
}

void SDLX_RenderLoop(void)
{	
	SDLX_Display *display;
    SDL_Texture     *tex;
	int x; int y;


	display = SDLX_get_display();
	tex = draw_scene(display);
    SDL_RenderCopy(display->renderer, tex, NULL, NULL);
	//draline();
	SDL_RenderPresent(display->renderer);
	SDL_RenderClear(display->renderer);
}

void SDLX_Update(void)
{
	SDLX_InputLoop();
	SDLX_RenderLoop();
}