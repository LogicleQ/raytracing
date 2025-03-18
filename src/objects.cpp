#include "objects.hpp"

std::vector<obj::object*> obj::objectList;

void obj::initObjects ()
{
	objectList.push_back(new Obj1());
}


void obj::clearObjects ()
{
	for (size_t i = 0; i < objectList.size(); ++i)
	{
		delete objectList[i];
	}
}



//customizable definitions go here

calc::p3 obj::lightPos = {-2, 2, 2};


float obj::Obj1::O (float x, float y, float z)
{
	return x*x + y*y + z*z - 1;
}

float obj::Obj1::O_x (float x, float y, float z)
{
	return 2*x;
}
float obj::Obj1::O_y (float x, float y, float z)
{
	return 2*y;
}
float obj::Obj1::O_z (float x, float y, float z)
{
	return 2*z;
}
