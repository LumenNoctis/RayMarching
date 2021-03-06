#ifndef RAYMARCH_H
# define RAYMARCH_H

# include "SDLX.h"
# include "MT.h"
# include "MT_vec3.h"//Angles Bad

# define MAX_ITER	 50
# define MIN_DIST	 0.01
# define X_VIEWANGLE 45.0 //Must be double else angle calculations gets funky
# define Y_VIEWANGLE 45.0
# define SMIN		 0.1
# define NTHREAD	 2
 
typedef  double (*SDF)(MT_Vector3, void *);

typedef struct Sphere
{
    MT_Vector3 position;
    double  radius;
} 			Sphere;

//Measurement : x = w | y = h | z = l
typedef struct
{
    MT_Vector3	position;
	MT_Vector3	volume;
} 			Box;

typedef struct
{
	MT_Vector3 positon;
	MT_Vector3 dimension;
}			Plane;

typedef struct
{
    MT_Vector3 position;
    
    double  x_angle;
    double  y_angle;
}           Camera;

typedef struct
{
	MT_Vector3 position;
	MT_Vector3 direction;
}				Light;

typedef struct
{
	void *objData;

	SDF  sdf;
}				Object;
typedef struct Ray
{
	MT_Vector3	position;
	double		distance;
	int			iteration;
}				Ray;
typedef struct
{
	Object	*objs;

	int 	objCount;
	Camera	cam;
	Light	light;
	MT_Vector3	screen[WIN_H][WIN_W];
}			Context;

double Sphere_SDF(MT_Vector3 cam, void *obj);
double Box_SDF(MT_Vector3 cam, void *obj);
double Some_SDF(MT_Vector3  cam, void *obj);

double SDF_Difference(double a, double b);
double SDF_Union(double a, double b);
double SDF_Intersection(double a, double b);
double SDF_SmoothMin(double a, double b);

MT_Vector3	CalcNormals(MT_Vector3 point, Object obj);
double 		CalcLighting(MT_Vector3 point, Light light, Object obj);


SDL_Texture *draw_scene(SDLX_Display *display);

void ComputeDeltas();
Context *get_context(void);

# endif