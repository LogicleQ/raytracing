#include "raytracing.hpp"

#include "objects.hpp"


//the iteration parameter is used for recusively calculating reflections
obj::color RT::rayCast (calc::p3 startPt, calc::vec3 direction, uint32_t iteration)
{


	calc::intersect hit = calc::cast(startPt, direction, true);


	//initial ray hit an object
	if (hit.defined)
	{

		calc::vec3 surfaceNorm = calc::normVec(hit.point, hit.obj);

		calc::vec3 vecToSource = -direction;
		calc::vec3 vecToLight{hit.point, obj::lightPos};

		calc::vec3 reflect = calc::rotVec(vecToSource, surfaceNorm, pi);

		//angle of separation between the reflection ray and the vector to light
		//used to calculate gloss
		float angSepToLight = calc::angleSep(reflect, vecToLight);


		//cast shadow ray
		float distToLight = calc::magnitude(calc::vec3{hit.point, obj::lightPos});
		calc::intersect shadowRay = calc::cast(hit.point, vecToLight, false, distToLight);



		//this is the calculated color of the surface before averaging it with any reflections
		obj::color mainCol;

		if (shadowRay.defined)
		{

			mainCol = obj::colorAvg
			({
				hit.obj->col << 1,
				{0, 0, 0, 3}
			});

		}
		else
		{
			mainCol = obj::colorAvg
			({
				hit.obj->col << 3,
				{0, 0, 0, 1}
			});

			mainCol = obj::gloss(mainCol, angSepToLight, hit.obj->glossDrop);

		}


		//calculate reflections
		if (iteration < calc::maxReflections)
		{

			//angle of separation between reflection and surface normal
			//the value described above ^^^ is equivalent to the angle of separation between vecToSource and surface normal
			float angSepToNorm = calc::angleSep(vecToSource, surfaceNorm);

			obj::color reflColor = rayCast(hit.point, reflect, iteration + 1);

			mainCol = obj::reflection(mainCol, reflColor, angSepToNorm, hit.obj->maxRefl, hit.obj->reflDrop, hit.obj->permRefl);
		}

		return mainCol;

	}
	else
	{
		//the ray did not intersect any object within the limit
		return obj::color{15, 15, 25};
	}


}
