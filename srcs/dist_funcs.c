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
	vec.x = MAX(fabs(box.position.x - cam.x) - box.volume
	.x, 0);
	vec.y = MAX(fabs(box.position.y - cam.y) - box.volume.y, 0);
	vec.z = MAX(fabs(box.position.z - cam.z) - box.volume.z, 0);

	return MT_V3Mag(vec);
}
//double Plane_SDF(MT_Vector3 cam, void *obj)
//{
//	Plane plane;

//	plane = *(Plane *)obj;
	
//}
