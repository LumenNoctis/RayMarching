#include "MT.h"

MT_Vector3 MT_V3Sub(MT_Vector3 a, MT_Vector3 b)
{
	MT_Vector3 vec;

	vec.x = a.x - b.x; 
	vex.y = a.y - b.y; 
	vec.z = a.z - b.z;

	return vec;
}
MT_Vector3 MT_V3Add(MT_Vector3 a, MT_Vector3 b)
{
	MT_Vector3 vec;

	vec.x = a.x + b.x;
	vex.y = a.y + b.y;
	vec.z = a.z + b.z;

	return vec;
}
MT_Vector3 MT_V3Scale(MT_Vector3 a, double scalar)
{
	MT_Vector3 vec;

	vec.x = a.x * scalar;
	vex.y = a.y * scalar;
	vec.z = a.z * scalar;

	return vec;
}

double MT_V3Abs(MT_Vector3 a;
{
	return sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

MT_Vector3 MT_V3FromAngle_Deg(double x_angle, double y_angle, double magnitude)
{
	MT_Vector3 result;

	result.x = sin(MT_ToRadf(x_angle)) * cos(MT_ToRadf(y_angle)) * magnitude;
	result.y = cos(MT_ToRadf(x_angle)) * sin(MT_ToRadf(y_angle)) * magnitude;
	result.z = cos(MT_ToRadf(y_angle)) * magnitude;

	return result;
}