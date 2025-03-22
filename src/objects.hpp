#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include "raytracing.hpp"

#include <vector>


namespace obj
{

	extern calc::p3 lightPos;

	struct color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;

		float weight{1};

		//temporarily return a color with a different weight
		color operator << (float newWeight);

		std::string to_string ()
		{
			return std::string{"color{"} + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ", " + std::to_string(weight) + "}";
		}

	};

	color colorAvg (std::vector<color> colors);

	color gloss (color col, float angle, float glossDrop);

	color reflection (color colMain, color colReflect, float angle, float maxRefl, float reflDrop, float permRefl);



	struct object
	{
		calc::p3 shiftOrigin = {0, 0, 0};

		color col = {0, 0, 0};

		float glossDrop = 0;

		float maxRefl = 0;
		float reflDrop = 0;
		float permRefl = 0;

		//main object function
		virtual float O (float, float, float) = 0;

		//partial derivatives
		virtual float O_x (float, float, float) = 0;
		virtual float O_y (float, float, float) = 0;
		virtual float O_z (float, float, float) = 0;

		//internal shift functions
		float O_shift (float, float, float);
		float O_x_shift (float, float, float);
		float O_y_shift (float, float, float);
		float O_z_shift (float, float, float);

		virtual ~object () {};

	};

	extern std::vector<object*> objectList;

	void initObjects ();
	void clearObjects ();


	struct Obj1 : object
	{
		Obj1();

		virtual float O (float, float, float);

		virtual float O_x (float, float, float);
		virtual float O_y (float, float, float);
		virtual float O_z (float, float, float);

	};

	struct Obj2 : object
	{
		Obj2();

		virtual float O (float, float, float);

		virtual float O_x (float, float, float);
		virtual float O_y (float, float, float);
		virtual float O_z (float, float, float);

	};

	struct Obj3 : object
	{
		Obj3();

		virtual float O (float, float, float);

		virtual float O_x (float, float, float);
		virtual float O_y (float, float, float);
		virtual float O_z (float, float, float);

	};

}



#endif
