#include "RayMarch.h"
#include "MT_vec.h"


double min(double a, double b)
{
	return (a > b) ? (b) : (a);
}

double max(double a, double b)
{
	return (a > b) ? (a) : (b);
}
int march_ray(double x_offset, double y_offset, Context context)
{
    int i;
	Camera tmp;
    MT_Vector3 movement;
	double distance;

    i = 0;
	tmp = context.cam;
	movement = MT_V3FromAngle_Deg(x_offset + tmp.x_angle , y_offset + tmp.y_angle, 1);
    while (i < MAX_ITER)
    {
        distance = Sphere_SDF(tmp, context.scene);
        distance = min(distance, Box_SDF(tmp, context.box));

		// distance = Some_SDF(tmp);
		if (distance < 0)
			return -1;
        if (distance <= MIN_DIST)
			return i;
		tmp.position.x += movement.x * distance;
		tmp.position.y += movement.y * distance;
		tmp.position.z += movement.z * distance;
		i++;
    }

	return MAX_ITER;
}

SDL_Texture	*draw_scene(SDLX_Display *display)
{
    int x;
    int y;
	int dist;
    SDL_Rect test;
	Uint32 c;

	double x_off;
	double y_off;

	double x_add;
	double y_add;

	Context *ctx;
	SDL_Surface *surf;

	ctx = get_context();
    x = 0;

	x_add = (X_VIEWANGLE / (WIN_W / 2));
	y_add = (Y_VIEWANGLE / (WIN_H / 2));

	x_off = -X_VIEWANGLE;
	y_off = -Y_VIEWANGLE;
    test.h = 2;
    test.w = 2; 
    // May need to use surfaces if drawing points directly to the screen is too slow
	// It is  
    surf = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32, 0xFF000000,0x00FF0000,0x0000FF00,0);
    c = 255;
    while (x < WIN_W)
    {
        test.x = x;
        y = 0;
		y_off = -Y_VIEWANGLE;
        while (y < WIN_H)
        {
            test.y = y;
			dist = march_ray(x_off, y_off, *ctx); //Put variables in consistent order when refactoring
			
			if (dist != MAX_ITER)
			{
				c = RGBA_to_int(dist * 20, dist * 20, dist * 20, 255);

			}
			set_pixel(surf, x, y, c);
			//SDL_RenderDrawPoint(display->renderer, x, y);
			c = 255;
            y++;
			y_off += y_add;
        }
		x_off += x_add;
        x++;
    }
    //SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 250);
    SDL_Texture *tex;
    //SDL_FillRect(surf, &test, 0xFF000000);
	tex = SDL_CreateTextureFromSurface(display->renderer, surf);
    SDL_FreeSurface(surf);
    printf("%p\n", tex);
    return tex;
}