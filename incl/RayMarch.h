#ifndef RAYMARCH_H
# define RAYMARCH_H

# include "SDLX.h"
# include "MT.h"
# include "MT_vec.h"

# define MAX_ITER 25
# define MIN_DIST 0.5
# define X_VIEWANGLE 45.0 //Must be double else angle calculations gets funky
# define Y_VIEWANGLE 45.0


typedef struct
{
    MT_Vector3 position;

    double  radius;
} 			Sphere;

//Measurement : x = w | y = h | z = l
typedef struct
{
    MT_Vector3 position;

	MT_Vector3 measurement;
} 			Box;

typedef struct
{
    MT_Vector3 position;
    
    double  x_angle;
    double  y_angle;
}           Camera;

typedef struct
{
	Sphere	scene;
	Box		box;
	Camera cam;
}			Context;

double Sphere_SDF(Camera cam, Sphere scene);
double Some_SDF(Camera  cam);


SDL_Texture *draw_scene(SDLX_Display *display);

Context *get_context(void);

# endif