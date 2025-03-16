#include "raytracing.hpp"

#include <iostream>

#include <cmath>

int main ()
{
	obj::initObjects();



	RT rt("Raytracing", win_width, win_height);

	rt.run();

}
