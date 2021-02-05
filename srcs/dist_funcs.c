#include "RayMarch.h"
#include <math.h>
#include "MT_vec3.h"

double Sphere_SDF(Camera cam, Sphere scene)
{
    return MT_GetDistance3D(cam.position, scene.position) - scene.radius;
}

double Box_SDF(Camera cam, Box box)
{
	MT_Vector3 distance;

	distance = MT_V3Sub(cam.position, MT_V3Add(box.pos, box.volume));

    return MT_V3Abs(distance);
}

double Cone_SDF(Camera cam, Sphere scene)
{
	double height_dist;

	height_dist = cam.position.y - (box.measurement.y + box.position.y);
    return MT_GetDistance3D(cam.position, scene.position) - scene.radius;
}

double Some_SDF(Camera  cam)
{
	return cam.position.x;
}