#include "raytracing.hpp"


void RT::run ()
{

	while (m_isRunning)
	{


		//clear screen
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
		SDL_RenderClear(m_renderer);




		//present buffer to screen
		SDL_RenderPresent(m_renderer);

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
