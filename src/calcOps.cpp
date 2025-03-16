#include "raytracing.hpp"

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




p3 calc::operator + (p3 pt, vec3 vec)
{
	return p3
	{
		pt.x + vec.x,
		pt.y + vec.y,
		pt.z + vec.z
	};
}

p3 calc::operator - (p3 pt, vec3 vec)
{
	return p3
	{
		pt.x - vec.x,
		pt.y - vec.y,
		pt.z - vec.z
	};
}

