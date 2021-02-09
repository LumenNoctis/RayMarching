#include "RayMarch.h"
#include "MT_vec3.h"

Ray MarchRay(MT_Vector3 direction, MT_Vector3 position, Object obj)
{
	double distance;
	Ray ray;

    ray.iteration = 0;
	ray.position = position;
    while (ray.iteration < MAX_ITER)
    {
        ray.distance = obj.sdf(ray.position, obj.objData);
		if (ray.distance < 0)
			break;
        if (ray.distance <= MIN_DIST)
			break;
		ray.position.x += (direction.x * distance);
		ray.position.y += (direction.y * distance);
		ray.position.z += (direction.z * distance);
		ray.iteration++;
    }
	return ray;
}

SDL_Texture	*draw_scene(SDLX_Display *display)
{
    int x;
    int y;
	int i;
	int currentDist;

	Uint32 color;

	double x_off;
	double y_off;

	double x_add;
	double y_add;

	double lighting;

	Object		hitobj;
	Ray			ray;
	Context 	*ctx;
	MT_Vector3	hitpos;
    SDL_Texture *tex;
	SDL_Surface *surf;

	ctx = get_context();

	x_add = (X_VIEWANGLE / (WIN_W / 2));
	y_add = (Y_VIEWANGLE / (WIN_H / 2));

	x_off = -X_VIEWANGLE;
	y_off = -Y_VIEWANGLE;
    // May need to use surfaces if drawing points directly to the screen is too slow
	// It is
	// Need to thread for more speed
    x = 0;
    surf = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32, 0xFF000000,0x00FF0000,0x0000FF00,0);
    while (x < WIN_W)
    {
        y = 0;
		y_off = -Y_VIEWANGLE;
        while (y < WIN_H)
        {
			i = 0;
			currentDist = MAX_ITER;
			color = 255;
			while (i < ctx->objCount)
			{
				ray = MarchRay(MT_V3FromAngle_Deg(x_off + ctx->cam.x_angle , y_off + ctx->cam.y_angle, 1),
								ctx->cam.position, ctx->objs[i]);
				if (ray.iteration < currentDist)
				{
					currentDist = ray.iteration;
					hitpos = ray.position;
					hitobj = ctx->objs[i];
				}
				i++;
			}
			if (currentDist < MAX_ITER)
			{
				lighting = CalcLighting(hitpos, ctx->light, hitobj);
				color = SDL_MapRGBA(surf->format, lighting * 255, 0, 0, 255);
			}
			SDLX_SetPixel(surf, x, y, color);
            y++;
			y_off += y_add;
        }
		x_off += x_add;
        x++;
    }
	tex = SDL_CreateTextureFromSurface(display->renderer, surf);
    SDL_FreeSurface(surf);

    return tex;
}