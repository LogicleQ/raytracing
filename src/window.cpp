#include "raytracing.hpp"

#include <string>

RT::RT (std::string title, int width, int height)
	: m_isRunning (true),
		m_title (title),
		m_width (width),
		m_height (height)
{

	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow(m_title.c_str(), m_width, m_height, 0);
	m_renderer = SDL_CreateRenderer(m_window, 0);

}
