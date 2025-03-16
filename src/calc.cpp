#include "raytracing.hpp"

#include <cmath>

using calc::p3;
using calc::vec3;



vec3 calc::operator + (vec3 vec1, vec3 vec2)
{
	return vec3
	{
		vec1.x + vec2.x,
		vec1.y + vec2.y,
		vec1.z + vec2.z
	};
}

vec3 calc::operator - (vec3 vec1, vec3 vec2)
{
	return vec3
	{
		vec1.x - vec2.x,
		vec1.y - vec2.y,
		vec1.z - vec2.z
	};
}

vec3 calc::operator * (vec3 vec, float sc)
{
	return vec3
	{
		vec.x * sc,
		vec.y * sc,
		vec.z * sc
	};
}
vec3 calc::operator * (float sc, vec3 vec)
{
	return vec * sc;
}

vec3 calc::operator / (vec3 vec, float sc)
{
	return vec3
	{
		vec.x / sc,
		vec.y / sc,
		vec.z / sc
	};
}




vec3 calc::unitVec (float theta, float phi)
{
	return vec3
	{
		(float) (cos(theta) * cos(phi)),
		(float) (sin(theta) * cos(phi)),
		(float) sin(phi)
	};
}

vec3 calc::unitVec (vec3 from)
{
	float mag = magnitude(from);

	if (mag == 0)
	{
		return vec3{0, 0, 0};
	};

	return from / mag;
}




float calc::magnitude (vec3 vec)
{
	return sqrt(vec.x * vec.x + vec.y + vec.y + vec.z + vec.z);
}




p3 calc::cast (p3 point, vec3 direction, bool doBinSearch)
{



}
