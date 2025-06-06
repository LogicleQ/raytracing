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


float calc::distance (p3 pt1, p3 pt2)
{
	p3 diff = pt2 - pt1;

	return sqrt(diff.x * diff.x + diff.y * diff.y + diff.z * diff.z);
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
		obj->O_x_shift(point.x, point.y, point.z),
		obj->O_y_shift(point.x, point.y, point.z),
		obj->O_z_shift(point.x, point.y, point.z)
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

	vec3 axis = unitVec({(float) (camDirection.theta - pi/2), 0});
	vec3 phiRot = rotVec(thetaRot, axis, camDirection.phi);

	theta = thetaGet(phiRot);
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

		if (obj->O_shift(midPt.x, midPt.y, midPt.z) > 0)
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

intersect calc::cast (p3 point, vec3 direction, bool doBinSearch, float maxLen)
{

	vec3 incVec = castIncLen * unitVec(direction);

	p3 trace = point;
	float traceLen = 0;
	while (traceLen < maxLen)
	{
		if (traceLen + castIncLen >= maxLen)
		{
			//it cannot go a full increment because it has reached the maxLen limit
			float remainingDist = maxLen - traceLen;
			incVec = remainingDist * unitVec(direction);
		}
		trace = trace + incVec;
		traceLen += castIncLen;


		std::vector<intersect> hitPts;

		intersect closestHitPt;
		float minDistance = maxLen; //this is the initial value to later find the minimum


		//calculate all intersections
		for (size_t i = 0; i < obj::objectList.size(); ++i)
		{

			obj::object* curObj = obj::objectList[i];

			//check if curObj is intersected at this point
			if (curObj->O_shift(trace.x, trace.y, trace.z) < 0)
			{

				//yes, intersected

				intersect hitPt;

				if (doBinSearch)
				{
					hitPt = {
						true,
						binSearch(trace - incVec, incVec, curObj),
						curObj
					};
				}
				else
				{
					hitPt = {
						true,
						trace - incVec,
						curObj
					};
				}

				hitPts.push_back(hitPt);

				//find the one closest to the source while going through this loop
				float dist = distance(trace - incVec, hitPt.point);
				if (dist < minDistance)
				{
					minDistance = dist;
					closestHitPt = hitPts.back();
				}

			}
		}


		//if any intersections were found, this will return the one closest to the source
		if (hitPts.size() > 0)
		{
			return closestHitPt;
		}


	}

	return intersect
	{
		false,
		p3{0, 0, 0},
		NULL
	};

}
