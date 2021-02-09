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
		ctx->cam.position.z += 1.5;
    if(keystate[SDL_SCANCODE_S])
		ctx->cam.position.z -= 1.5;
    if(keystate[SDL_SCANCODE_D])
		ctx->cam.position.x += 1.5;
    if(keystate[SDL_SCANCODE_A])
		ctx->cam.position.x -= 1.5;
    if(keystate[SDL_SCANCODE_SPACE])
		ctx->cam.position.y += 1.5;
    if(keystate[SDL_SCANCODE_X])
		ctx->cam.position.y -= 1.5;

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

void SDLX_RenderLoop(void)
{	
	SDLX_Display *display;
    SDL_Texture     *tex;

	display = get_display();
	tex = draw_scene(display);
	//draw_scene(display);
    SDL_RenderCopy(display->renderer, tex, NULL, NULL);
	// SDL_RenderCopy(display->renderer, draw_scene(display), NULL, NULL);
	SDL_RenderPresent(display->renderer);
	SDL_RenderClear(display->renderer);
}

void SDLX_Update(void)
{
	SDLX_InputLoop();
	SDLX_RenderLoop();
}