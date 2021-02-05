#include "RayMarch.h"

double SDF_Intersection(double a, double b)
{
	return (max(a, b));
}

double SDF_Union(double a, double b)
{
	return (min(a, b));
}

double SDF_Difference(double a, double b)
{
	return (max(a, -b));
}