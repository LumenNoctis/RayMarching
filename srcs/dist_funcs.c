#include "RayMarch.h"
#include <math.h>
#include "MT_vec.h"

double Sphere_SDF(Camera cam, Sphere scene)
{
    return MT_GetDistance3D(cam.position, scene.position) - scene.radius;
}

double Some_SDF(Camera  cam)
{
	return cam.position.x;
}