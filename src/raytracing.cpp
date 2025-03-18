#include "raytracing.hpp"
#include <SDL3/SDL_render.h>


#include "objects.hpp"

#include <iostream>


void RT::run ()
{

	size_t x = 0;
	size_t y = 0;

	bool rendering = true;


	//clear screen
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);

	SDL_RenderPresent(m_renderer);

	while (m_isRunning)
	{


		if (rendering)
		{

			calc::norm n = calc::coordNorm(x, y);
			calc::vec3 dir = calc::unitVec(calc::normToAngles(n));

			calc::intersect hit = calc::cast(camPos, dir, true);


			//initial ray hit an object
			if (hit.defined)
			{

				calc::vec3 axis = calc::normVec(hit.point, hit.obj);

				calc::vec3 vecToCam{hit.point, camPos};
				calc::vec3 vecToLight{hit.point, obj::lightPos};

				calc::vec3 reflect = calc::rotVec(vecToCam, axis, pi);

				float angSep = calc::angleSep(reflect, vecToLight);


				//cast shadow ray
				calc::intersect shadowRay = calc::cast(hit.point, vecToLight, false);


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





			++x;
			if (x >= win_width)
			{
				x = 0;
				++y;
				printf("%d, %d\n", x, y);
			}
			if (y >= win_height)
			{
				rendering = false;
				SDL_RenderPresent(m_renderer);
				printf("done\n");
			}


		}



		//poll events
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_EVENT_QUIT:
					m_isRunning = false;
					break;
			}
		}

	}

}
