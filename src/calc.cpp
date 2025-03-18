#include "raytracing.hpp"

#include "objects.hpp"

#include <cmath>

using calc::p3;
using calc::vec3;
using calc::anglePair;
using calc::intersect;
using calc::norm;



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



vec3 calc::unitVec (anglePair angs)
{
	return vec3
	{
		(float) (cos(angs.theta) * cos(angs.phi)),
		(float) (sin(angs.theta) * cos(angs.phi)),
		(float) sin(angs.phi)
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
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
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


float calc::angleSep (vec3 vec1, vec3 vec2)
{
	return acos(dot(vec1, vec2) / (magnitude(vec1) * magnitude(vec2)));
}


vec3 calc::normVec (p3 point, obj::object* obj)
{
	return vec3
	{
		obj->O_x(point.x, point.y, point.z),
		obj->O_y(point.x, point.y, point.z),
		obj->O_z(point.x, point.y, point.z)
	};
}

vec3 calc::rotVec (vec3 vec, vec3 axis, float theta)
{
	vec3 unitAxis = unitVec(axis);

	return vec * cos(theta) + cross(unitAxis, vec) * sin(theta) + unitAxis * dot(unitAxis, vec) * (1 - cos(theta));
}





//middle is the origin, upwards and rightwards is positive
//based on width, not height
norm calc::coordNorm (uint32_t x, uint32_t y)
{
	return norm
	{
		(2.0f * x) / win_width - 1,
		(2.0f * (win_height - y) - win_height) / win_width
	};
}



anglePair calc::normToAngles (norm n)
{

	float theta = -atan(n.x * tan(apertureAngle));
	float phi = atan2(n.y * tan(apertureAngle), std::abs(1 / cos(theta)));

	theta = theta + camDirection.theta;
	vec3 thetaRot = unitVec({theta, phi});

	vec3 axis = unitVec({(float) (theta - pi/2), 0});
	vec3 phiRot = rotVec(thetaRot, axis, camDirection.phi);

	phi = phiGet(phiRot);

	return anglePair{theta, phi};

}




p3 calc::binSearch (p3 point, vec3 incVec, obj::object* obj)
{
	p3 p1 = point;
	p3 p2 = point + incVec;
	p3 midPt;


	for (size_t i = 0; i < binSearchIters; ++i)
	{

		midPt = (p1 + p2) / 2;

		if (obj->O(midPt.x, midPt.y, midPt.z) > 0)
		{
			p1 = midPt;
		}
		else
		{
			p2 = midPt;
		}

	}

	return midPt;
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

			obj::object* obj = obj::objectList[i];

			if (obj->O(trace.x, trace.y, trace.z) < 0)
			{
				//intersected an object
				if (doBinSearch)
				{
					return intersect
					{
						true,
						binSearch(trace - incVec, incVec, obj),
						obj
					};
				}
				else
				{

					return intersect
					{
						true,
						trace - incVec,
						obj
					};
				}
			}
		}
	}

	return intersect
	{
		false,
		p3{0, 0, 0},
		NULL
	};

}
