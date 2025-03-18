#include "objects.hpp"

void obj::initObjects ()
{

	//any defined objects must be entered into this initialization function

	objectList.push_back(new Obj1());

}




calc::p3 obj::lightPos = {-2.5, 2, 2};





//Object 1


obj::Obj1::Obj1 ()
{
	col = {255, 0, 0};

	glossDrop = 1.5;
}

float obj::Obj1::O (float x, float y, float z)
{
	return x*x*x*x + y*y*y*y + z*z*z*z - 1;
}

float obj::Obj1::O_x (float x, float y, float z)
{
	return 4*x*x*x;
}
float obj::Obj1::O_y (float x, float y, float z)
{
	return 4*y*y*y;
}
float obj::Obj1::O_z (float x, float y, float z)
{
	return 4*z*z*z;
}


