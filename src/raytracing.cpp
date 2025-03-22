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

	uint8_t percentDone = 0;

	while (m_isRunning)
	{


		if (rendering)
		{

			calc::norm n = calc::coordNorm(x, y);
			calc::vec3 dir = calc::unitVec(calc::normToAngles(n));


			//cast the full ray for this pixel
			obj::color pixelColor = rayCast(camPos, dir, 0);

			SDL_SetRenderDrawColor(m_renderer, pixelColor.r, pixelColor.g, pixelColor.b, 255);

			SDL_RenderPoint(m_renderer, x, y);

			++x;

			size_t ind = x + m_width * y;
			const size_t maxInd = m_width * m_height;

			if (100.0 * ind / maxInd >= percentDone + 10)
			{
				percentDone += 10;
				printf("%d%%\n", percentDone);
			}

			if (x >= m_width)
			{
				x = 0;
				++y;
			}
			if (y >= m_height)
			{
				rendering = false;
				SDL_RenderPresent(m_renderer);
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
