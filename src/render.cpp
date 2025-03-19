#include "raytracing.hpp"

#include "objects.hpp"

#include <iostream>


obj::color rayCast (calc::p3 startPt, calc::vec3 direction, uint32_t iteration)
{


	calc::intersect hit = calc::cast(startPt, direction, true);


	#error fix the stuff below:
	#error e.g. change all camPos to startPt

	//initial ray hit an object
	if (hit.defined)
	{

		calc::vec3 axis = calc::normVec(hit.point, hit.obj);

		calc::vec3 vecToCam{hit.point, camPos};
		calc::vec3 vecToLight{hit.point, obj::lightPos};

		calc::vec3 reflect = calc::rotVec(vecToCam, axis, pi);

		float angSep = calc::angleSep(reflect, vecToLight);


		//cast shadow ray
		float distToLight = calc::magnitude(calc::vec3{hit.point, obj::lightPos});
		calc::intersect shadowRay = calc::cast(hit.point, vecToLight, false, distToLight);


		//std::cout << reflect.to_string() << std::endl;

		if (shadowRay.defined)
		{
			obj::color col = obj::colorAvg
			({
				hit.obj->col << 1,
				{0, 0, 0, 2}
			});

			SDL_SetRenderDrawColor(m_renderer, col.r, col.g, col.b, 255);
		}
		else
		{
			obj::color col = obj::colorAvg
			({
				hit.obj->col << 3,
				{0, 0, 0, 1}
			});

			col = obj::gloss(col, angSep, hit.obj->glossDrop);

			SDL_SetRenderDrawColor(m_renderer, col.r, col.g, col.b, 255);
		}

		SDL_RenderPoint(m_renderer, x, y);
	}
	else
	{
		SDL_SetRenderDrawColor(m_renderer, 25, 25, 40, 255);
		SDL_RenderPoint(m_renderer, x, y);
	}




}
