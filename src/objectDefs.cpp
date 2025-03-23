#include "objects.hpp"

void obj::initObjects ()
{

	//any defined objects must be entered into this initialization function to be rendered

	objectList.push_back(new Cube1());
	objectList.push_back(new Sphere1());
	objectList.push_back(new Sphere2());
	objectList.push_back(new Floor());

}




calc::p3 obj::lightPos = {-15, 11, 15};




// red rounded cube

obj::Cube1::Cube1 ()
{
	shiftOrigin = {0, 0, 2};

	col = {255, 0, 0};

	glossDrop = 1.5;

	maxRefl = 0;
	reflDrop = 0;
	permRefl = 0.3;
}

float obj::Cube1::O (float x, float y, float z)
{
	return x*x*x*x*x*x*x*x*x*x + y*y*y*y*y*y*y*y*y*y + z*z*z*z*z*z*z*z*z*z - 1;
}

float obj::Cube1::O_x (float x, float y, float z)
{
	return 10*x*x*x*x*x*x*x*x*x;
}
float obj::Cube1::O_y (float x, float y, float z)
{
	return 10*y*y*y*y*y*y*y*y*y;
}
float obj::Cube1::O_z (float x, float y, float z)
{
	return 10*z*z*z*z*z*z*z*z*z;
}



// green sphere

obj::Sphere1::Sphere1 ()
{
	shiftOrigin = {-1.7, 2, 3};

	col = {20, 230, 50};

	glossDrop = 1.5;

	maxRefl = 0;
	reflDrop = 0;
	permRefl = 0.45;
}

float obj::Sphere1::O (float x, float y, float z)
{
	return x*x + y*y + z*z - 0.7;
}

float obj::Sphere1::O_x (float x, float y, float z)
{
	return 2*x;
}
float obj::Sphere1::O_y (float x, float y, float z)
{
	return 2*y;
}
float obj::Sphere1::O_z (float x, float y, float z)
{
	return 2*z;
}




// other sphere

obj::Sphere2::Sphere2 ()
{
	shiftOrigin = {-4, 1.5, 2.5};

	col = {20, 50, 70};

	glossDrop = 2;

	maxRefl = 0;
	reflDrop = 0;
	permRefl = 0.8;
}

float obj::Sphere2::O (float x, float y, float z)
{
	return x*x + y*y + z*z - 0.2;
}

float obj::Sphere2::O_x (float x, float y, float z)
{
	return 2*x;
}
float obj::Sphere2::O_y (float x, float y, float z)
{
	return 2*y;
}
float obj::Sphere2::O_z (float x, float y, float z)
{
	return 2*z;
}




// floor

obj::Floor::Floor ()
{
	shiftOrigin = {0, 0, 0};

	col = {80, 100, 140};

	glossDrop = 2;

	maxRefl = 0.8;
	reflDrop = 1.5;
	permRefl = 0.3;
}

float obj::Floor::O (float x, float y, float z)
{
	return z;
}

float obj::Floor::O_x (float x, float y, float z)
{
	return 0;
}
float obj::Floor::O_y (float x, float y, float z)
{
	return 0;
}
float obj::Floor::O_z (float x, float y, float z)
{
	return 1;
}

