#include "raytracing.hpp"

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


			rayCast(camPos, dir, 0);



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
