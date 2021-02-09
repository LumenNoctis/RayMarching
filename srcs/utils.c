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