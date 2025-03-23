#ifndef RAYTRACING_HPP
#define RAYTRACING_HPP

#include <string>

#include <SDL3/SDL.h>



extern uint32_t win_width;
extern uint32_t win_height;



//this is a forward declaration
//the actual declaration is further down this file
namespace calc
{
	struct p3;
	struct vec3;
};

//this is also a forward declaration
namespace obj
{
	struct object;
	struct color;
}


class RT
{

	public:
		RT (std::string title, int width, int height);

		void run ();

		obj::color rayCast (calc::p3 startPt, calc::vec3 direction, uint32_t iteration);


	private:
		bool m_isRunning;

		std::string m_title;

		int m_width;
		int m_height;

		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

};






const double pi = 3.1415926535897932;

namespace calc
{

	struct p3
	{
		float x;
		float y;
		float z;

		std::string to_string ()
		{
			return std::string{"p3{"} + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "}";
		}
	};

	struct vec3
	{
		float x;
		float y;
		float z;

		vec3 (float _x, float _y, float _z)
			: x {_x},
				y {_y},
				z {_z}
		{}

		vec3 (p3 from, p3 to)
			: x {to.x - from.x},
				y {to.y - from.y},
				z {to.z - from.z}
		{}

		std::string to_string ()
		{
			return std::string{"vec3{"} + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "}";
		}
	};

	vec3 operator + (vec3 vec1, vec3 vec2);
	vec3 operator - (vec3 vec1, vec3 vec2);
	vec3 operator - (vec3 vec);
	vec3 operator * (vec3 vec, float sc);
	vec3 operator * (float sc, vec3 vec);
	vec3 operator / (vec3 vec, float sc);

	float dot (vec3 vec1, vec3 vec2);
	vec3 cross (vec3 vec1, vec3 vec2);

	p3 operator + (p3 pt1, p3 pt2);
	p3 operator + (p3 pt, vec3 vec);
	p3 operator - (p3 pt1, p3 pt2);
	p3 operator - (p3 pt, vec3 vec);
	p3 operator * (p3 pt, float sc);
	p3 operator / (p3 pt, float sc);






	struct anglePair
	{
		float theta;
		float phi;

		std::string to_string ()
		{
			return std::string{"anglePair{"} + std::to_string(theta) + ", " + std::to_string(phi) + "}";
		}
	};




	float mod (float a, float b);

	vec3 unitVec (anglePair angs);
	vec3 unitVec (vec3 from);

	float magnitude (vec3 vec);
	float distance (p3 pt1, p3 pt2);

	float thetaGet (vec3 vec);
	float phiGet (vec3 vec);

	float angleSep (vec3 vec1, vec3 vec2);

	vec3 normVec (p3 point, obj::object* obj);

	vec3 rotVec (vec3 vec, vec3 axis, float theta);



	struct norm
	{
		float x;
		float y;

		std::string to_string ()
		{
			return std::string{"norm{"} + std::to_string(x) + ", " + std::to_string(y) + "}";
		}
	};

	norm coordNorm (uint32_t x, uint32_t y);




	anglePair normToAngles (norm n);




	struct intersect
	{
		bool defined;
		p3 point;
		obj::object* obj;
	};

	extern float binSearchIters;

	extern float castIncLen;
	extern float castMaxLen;

	extern uint32_t maxReflections;

	p3 binSearch (p3 point, vec3 incVec, obj::object* obj);
	intersect cast (p3 point, vec3 direction, bool doBinSearch, float maxLen = castMaxLen);

};

extern calc::p3 camPos;

extern calc::anglePair camDirection;

extern float apertureAngle;

#endif
