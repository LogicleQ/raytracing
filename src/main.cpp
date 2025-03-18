#include <iostream>

#include <cmath>

#include "raytracing.hpp"
#include "objects.hpp"

int main ()
{
	obj::initObjects();




	RT rt("Raytracing", win_width, win_height);

	rt.run();


	obj::clearObjects();

}
