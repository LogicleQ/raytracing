#include "objects.hpp"

void obj::initObjects ()
{

	//any defined objects must be entered into this initialization function

	objectList.push_back(new Obj1());
	objectList.push_back(new Obj2());
	objectList.push_back(new Obj3());

}




calc::p3 obj::lightPos = {-15, 11, 15};





//Object 1 (rounded cube)

obj::Obj1::Obj1 ()
{
	shiftOrigin = {0, 0, 2};

	col = {255, 0, 0};

	glossDrop = 1.5;

	maxRefl = 0;
	reflDrop = 0;
	permRefl = 0.3;
}

float obj::Obj1::O (float x, float y, float z)
{
	return x*x*x*x*x*x*x*x + y*y*y*y*y*y*y*y + z*z*z*z*z*z*z*z - 1;
}

float obj::Obj1::O_x (float x, float y, float z)
{
	return 8*x*x*x*x*x*x*x;
}
float obj::Obj1::O_y (float x, float y, float z)
{
	return 8*y*y*y*y*y*y*y;
}
float obj::Obj1::O_z (float x, float y, float z)
{
	return 8*z*z*z*z*z*z*z;
}



// Object 2 (sphere)

obj::Obj2::Obj2 ()
{
	shiftOrigin = {-1.7, 2, 3};

	col = {20, 230, 50};

	glossDrop = 1.5;

	maxRefl = 0;
	reflDrop = 0;
	permRefl = 0.45;
}

float obj::Obj2::O (float x, float y, float z)
{
	return x*x + y*y + z*z - 0.7;
}

float obj::Obj2::O_x (float x, float y, float z)
{
	return 2*x;
}
float obj::Obj2::O_y (float x, float y, float z)
{
	return 2*y;
}
float obj::Obj2::O_z (float x, float y, float z)
{
	return 2*z;
}



// Object 3 (floor)

obj::Obj3::Obj3 ()
{
	shiftOrigin = {0, 0, 0};

	col = {80, 100, 140};

	glossDrop = 1.5;

	maxRefl = 0.5;
	reflDrop = 1.5;
	permRefl = 0.3;
}

float obj::Obj3::O (float x, float y, float z)
{
	return z;
}

float obj::Obj3::O_x (float x, float y, float z)
{
	return 0;
}
float obj::Obj3::O_y (float x, float y, float z)
{
	return 0;
}
float obj::Obj3::O_z (float x, float y, float z)
{
	return 1;
}

