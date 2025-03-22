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

vec3 calc::operator - (vec3 vec)
{
	return vec3
	{
		-vec.x,
		-vec.y,
		-vec.z
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


float calc::dot (vec3 vec1, vec3 vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

vec3 calc::cross (vec3 vec1, vec3 vec2)
{
	return vec3
	{
		vec1.y * vec2.z - vec1.z * vec2.y,
		-(vec1.x * vec2.z - vec1.z * vec2.x),
		vec1.x * vec2.y - vec1.y * vec2.x
	};
}






p3 calc::operator + (p3 pt1, p3 pt2)
{
	return p3
	{
		pt1.x + pt2.x,
		pt1.y + pt2.y,
		pt1.z + pt2.z
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

p3 calc::operator - (p3 pt1, p3 pt2)
{
	return p3
	{
		pt1.x - pt2.x,
		pt1.y - pt2.y,
		pt1.z - pt2.z
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

p3 calc::operator * (p3 pt, float sc)
{
	return p3
	{
		pt.x * sc,
		pt.y * sc,
		pt.z * sc
	};
}

p3 calc::operator / (p3 pt, float sc)
{
	return p3
	{
		pt.x / sc,
		pt.y / sc,
		pt.z / sc
	};
}

