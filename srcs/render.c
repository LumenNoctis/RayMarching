#include "RayMarch.h"
#include "MT_vec3.h"
#include "MT_vec2.h"

SDL_Surface *surf;
typedef struct Info
{
	int y;
	double y_angle;
	double screenY;
}				Info;

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

int	GetPixelColor(double x_angle, double y_angle, double sx, double sy, int x, int y)
{
	Ray			newRay;
	Ray			oldRay;
	Object		hitobj;
	Context 	*ctx;
	MT_Vector3 position;
	MT_Vector3 direction;

	double lighting;
	int i;

	i = 0;
	ctx = get_context();
	oldRay.iteration = MAX_ITER;
	while (i < ctx->objCount)
	{
		//position = ctx->cam.position;
		position.x = ctx->cam.position.x + sx;
		position.y = ctx->cam.position.y + sy;
		position.z = ctx->cam.position.z;
		direction.x = sx;
		direction.y = sy;
		direction.z = 1;
		//direction = MT_V3Normalize(direction);
		//direction = ctx->screen[y][x];
		//direction = MT_V3FromAngle_Deg(x_angle + ctx->cam.x_angle,
		//y_angle + ctx->cam.y_angle, 1);
		//if (x_angle == -X_VIEWANGLE || x_angle == X_VIEWANGLE)
		//{
		//	SDL_Log("x %f y %f z %f", direction.x, direction.y, direction.z);
		//}
		newRay = MarchRay(direction,
		position, ctx->objs[i]);
		if (newRay.iteration < oldRay.iteration)
		{
			oldRay.iteration = newRay.iteration;
			oldRay.position = newRay.position;
			hitobj = ctx->objs[i];
		}
		i++;       
	}
	if (oldRay.iteration < MAX_ITER)
	{
		lighting = CalcLighting(oldRay.position, ctx->light, hitobj);
		return SDL_MapRGBA(surf->format, 255 * lighting, 0, 0, 255);
	}
	return 255;
}

void DrawRow(Info *info)
{
    int x;
	int i;
	double	x_angle;
	double	lighting;
	double screenX;

	Uint32 color;
	SDLX_Display *display;

	display = SDLX_get_display();
	x = 0;
	screenX = -(WIN_W / 2); 
	x_angle = -X_VIEWANGLE;
	while (x < WIN_H)
	{
		color = GetPixelColor(x_angle, info->y_angle, screenX, info->screenY, x, info->y);
		SDLX_SetPixel(surf, x, info->y, color);
		x_angle += (X_VIEWANGLE / (WIN_W / 2));
		x++;
		screenX++;
	}
}

SDL_Texture	*draw_scene(SDLX_Display *display)
{
    int y;
	double angle;
	double screenY;
	
	Context *ctx;
	SDL_Thread *thread;
    SDL_Texture *tex;
	Info info;

    y = 0;
	screenY = -(WIN_H / 2); 
	ctx = get_context();
	angle = -Y_VIEWANGLE;
    surf = SDL_CreateRGBSurface(0, WIN_W, WIN_H, 32, 0xFF000000,0x00FF0000,0x0000FF00,0);
    while (y < WIN_W)
    {
		info.screenY = screenY;
		info.y_angle = angle;
		info.y = y;
		DrawRow(&info);
        y++;
		screenY++;
		angle += (Y_VIEWANGLE / (WIN_H / 2));
    }
	//SDL_FillRect(surf, &(SDL_Rect){0, 0, 100, 100}, 0x0000FFFF);
	tex = SDL_CreateTextureFromSurface(display->renderer, surf);
    SDL_FreeSurface(surf);
	//exit(0);
    return tex;
}