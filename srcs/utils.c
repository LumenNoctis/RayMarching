#include "RayMarch.h"

double SDF_Intersection(double a, double b)
{
	return (MAX(a, b));
}

double SDF_Union(double a, double b)
{
	return (MIN(a, b));
}

double SDF_Difference(double a, double b)
{
	return (MAX(a, -b));
}

double SDF_SmoothMin(double a, double b)
{
	double h;

	h = MAX(SMIN - fabs(a - b), 0.0) / SMIN;
	return MIN(a, b) - h * h * h * SMIN * (1.0 / 6.0);
}

void ComputeDeltas()
{
	Context *ctx;
	double x_angle;
	double y_angle;
	int 	x;
	int 	y;

	ctx = get_context();
	y_angle = -(WIN_H / 2);
	y = 0;
	SDL_Log("Computing deltas");
	while (y < WIN_H)
	{	
		x = 0;
		x_angle = -(WIN_W / 2);
		while (x < WIN_W)
		{
			ctx->screen[y][x].x = tan(x_angle);
			ctx->screen[y][x].y = tan(y_angle) * (1 / cos(x_angle));
			ctx->screen[y][x].z = 1;
			x++;
			x_angle += ((WIN_W / 2));
		}
		y++;
		y_angle += (WIN_H / 2); 
	}
	SDL_Log("Done");
}