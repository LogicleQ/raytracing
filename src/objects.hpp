#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include "raytracing.hpp"

#include <vector>


namespace obj
{

	extern calc::p3 lightPos;

	struct object
	{
		//main object function
		virtual float O (float, float, float) = 0;

		//partial derivatives
		virtual float O_x (float, float, float) = 0;
		virtual float O_y (float, float, float) = 0;
		virtual float O_z (float, float, float) = 0;

	};

	extern std::vector<object*> objectList;

	void initObjects ();
	void clearObjects ();


	struct Obj1 : object
	{
		virtual float O (float, float, float);

		virtual float O_x (float, float, float);
		virtual float O_y (float, float, float);
		virtual float O_z (float, float, float);

	};

}



#endif
