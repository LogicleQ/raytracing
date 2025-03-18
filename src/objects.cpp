#include "objects.hpp"

std::vector<obj::object*> obj::objectList;



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
obj::color obj::gloss (color col, float angle, float glossDrop)
{

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
