#include "raytracing.hpp"

#include <iostream>

int main ()
{
	obj::initObjects();


	RT rt("Raytracing", 500, 400);

	rt.run();

}
