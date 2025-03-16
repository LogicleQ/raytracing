#include "raytracing.hpp"

std::vector<obj::object> obj::objectList;

void obj::initObjects ()
{
	obj::objectList.push_back(
		obj::object{
		&obj::O1, &obj::O1_x, &obj::O1_y, &obj::O1_z
		}
	);
}



float obj::O1 (float x, float y, float z)
{
	return x*x + y*y + z*z - 1;
}

float obj::O1_x (float x, float y, float z)
{
	return 2*x;
}

float obj::O1_y (float x, float y, float z)
{
	return 2*y;
}

float obj::O1_z (float x, float y, float z)
{
	return 2*z;
}
