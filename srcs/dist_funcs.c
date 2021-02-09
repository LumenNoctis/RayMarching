#include "RayMarch.h"
#include <math.h>
#include "MT_vec3.h"

double Sphere_SDF(MT_Vector3 cam, void 	*obj)
{
	Sphere sphere;

	sphere = *(Sphere *)obj;
    return MT_GetDistance3D(cam, sphere.position) - sphere.radius;
}

double Box_SDF(MT_Vector3 cam, void *obj)
{
	MT_Vector3 vec;
	Box box;

	box = *(Box *)obj;
	vec.x = MAX(fabs(box.position.x - cam.x) - box.volume.x, 0);
	vec.y = MAX(fabs(box.position.y - cam.y) - box.volume.y, 0);
	vec.z = MAX(fabs(box.position.z - cam.z) - box.volume.z, 0);

	return MT_V3Mag(vec);
}

double Some_SDF(MT_Vector3  cam, void *obj)
{
	MT_Vector3 vec;
	double x;
	double y;
	double z;

	//vec.x = MAX((box.volume.x) - cam.position.x, 0);
	//vec.y = MAX((box.volume.y) - cam.position.y, 0);
	//vec.z = MAX((box.volume.z) - cam.position.z, 0);
	//x = MT_V3Abs(cam.position);
	//vec.x = (box.position.x + box.volume.x);
	////vec.y = (box.position.y + box.volume.y);
	//vec.z = (box.position.z + box.volume.z);

	//vec.x = fabs(cam.x - box.position.x);
	//vec.y = fabs(cam.y - box.position.y);
	//vec.z = fabs(cam.z - box.position.z);
	
	//vec.x = sin(box.position.x + box.volume.x - cam.x) + (vec.y);
	//vec.y = MIN(box.position.y * box.volume.y - (vec.y), (vec.x));
	//vec.z = (box.position.z + (box.volume.z - vec.z));


	return (vec.z) + (vec.x  + vec.y);
    //return MAX(MT_V3Abs(MT_V3Sub(vec, cam.position)), 0);
}