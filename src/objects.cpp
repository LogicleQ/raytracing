#include "objects.hpp"

std::vector<obj::object*> obj::objectList;



float obj::object::O_shift (float x, float y, float z)
{
	return O(x - shiftOrigin.x, y - shiftOrigin.y, z - shiftOrigin.z);
}

float obj::object::O_x_shift (float x, float y, float z)
{
	return O_x(x - shiftOrigin.x, y - shiftOrigin.y, z - shiftOrigin.z);
}

float obj::object::O_y_shift (float x, float y, float z)
{
	return O_y(x - shiftOrigin.x, y - shiftOrigin.y, z - shiftOrigin.z);
}

float obj::object::O_z_shift (float x, float y, float z)
{
	return O_z(x - shiftOrigin.x, y - shiftOrigin.y, z - shiftOrigin.z);
}





void obj::clearObjects ()
{
	for (size_t i = 0; i < objectList.size(); ++i)
	{
		delete objectList[i];
	}
}

obj::color obj::color::operator << (float newWeight)
{
	return color{r, g, b, newWeight};
}


obj::color obj::colorAvg (std::vector<obj::color> colors)
{

	uint32_t red = 0, green = 0, blue = 0;

	float weightSum = 0;

	for (size_t i = 0; i < colors.size(); ++i)
	{
		float weight = colors[i].weight;

		red += colors[i].r * weight;
		green += colors[i].g * weight;
		blue += colors[i].b * weight;

		weightSum += weight;
	}


	return obj::color
	{
		(uint8_t) (red / weightSum),
		(uint8_t) (green / weightSum),
		(uint8_t) (blue / weightSum),
		1
	};

}

//angle parameter is the angle of separation between the reflection vector and the vector to light
//set glossDrop = -1 for no gloss effect
obj::color obj::gloss (color col, float angle, float glossDrop)
{

	if (glossDrop == -1)
	{
		return col;
	}

	if (glossDrop * angle < 1)
	{

		return colorAvg
		({
			{255, 255, 255, 1 - glossDrop * angle},
			col << glossDrop * angle
		});

	}
	else
	{
		return col;
	}

}

//angle parameter is the angle of separation between the surface normal vector and the negative of the incident ray vector
//maxRefl and permRefl should be within 0 (no reflection) and 1 (complete reflection)
obj::color obj::reflection (color colMain, color colReflect, float angle, float maxRefl, float reflDrop, float permRefl)
{

	float refl = reflDrop * (angle - pi/2) + maxRefl;

	if (refl < permRefl)
	{
		refl = permRefl;
	}

	return colorAvg
	({
		colReflect << refl,
		colMain << 1 - refl
	});

}
