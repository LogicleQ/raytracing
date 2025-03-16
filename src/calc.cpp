#include "raytracing.hpp"

#include <cmath>

using calc::p3;
using calc::vec3;
using calc::intersect;



float calc::mod (float a, float b)
{
	while (a >= b)
	{
		a -= b;
	}
	while (a < 0)
	{
		a += b;
	}

	return a;
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


float calc::thetaGet (vec3 vec)
{
	float theta = atan2(vec.y, vec.x);

	return mod(theta, 2*pi);
}

float calc::phiGet (vec3 vec)
{
	float baseLen = sqrt(vec.x * vec.x + vec.y * vec.y);

	return atan2(vec.z, baseLen);
}




intersect calc::cast (p3 point, vec3 direction, bool doBinSearch)
{

	vec3 incVec = castIncLen * unitVec(direction);

	p3 trace = point;
	float traceLen = 0;
	while (traceLen + castIncLen < castMaxLen)
	{
		trace = trace + incVec;
		traceLen += castIncLen;

		for (size_t i = 0; i < obj::objectList.size(); ++i)
		{
			if (obj::objectList[i].O(trace.x, trace.y, trace.z) < 0)
			{
				return intersect
				{
					true,
					trace - incVec,
					i
				};
			}
		}
	}

	return intersect
	{
		false,
		p3{0, 0, 0},
		0
	};

}




