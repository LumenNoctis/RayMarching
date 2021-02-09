#include "RayMarch.h"


MT_Vector3 CalcNormals(MT_Vector3 point, Object obj)
{
	MT_Vector3 normal;

	//Here approximating the derivative instead of actually completely calculating it
	normal.x = obj.sdf((MT_Vector3) {point.x + FLT_EPSILON, point.y, point.z}, obj.objData) -
				obj.sdf((MT_Vector3){point.x - FLT_EPSILON, point.y, point.z}, obj.objData);

	normal.y = obj.sdf((MT_Vector3) {point.x, point.y + FLT_EPSILON, point.z}, obj.objData) -
				obj.sdf((MT_Vector3){point.x, point.y - FLT_EPSILON, point.z}, obj.objData);

	normal.z = obj.sdf((MT_Vector3) {point.x, point.y, point.z + FLT_EPSILON}, obj.objData) -
				obj.sdf((MT_Vector3){point.x, point.y, point.z - FLT_EPSILON}, obj.objData);

	return MT_V3Normalize(normal);
}


double CalcLighting(MT_Vector3 point, Light light, Object obj)
{
	MT_Vector3 normal;
	double val;

	normal = CalcNormals(point, obj);
	val = MT_V3Dot(normal, light.direction, NULL);
	
	//Not max of 0 else will be completely black
	return MAX(val, 0.2);
}