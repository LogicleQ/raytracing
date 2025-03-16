#ifndef RAYTRACING_HPP
#define RAYTRACING_HPP

#include <string>
#include <vector>

#include <SDL3/SDL.h>

extern uint32_t win_width;
extern uint32_t win_height;

class RT
{

	public:
		RT (std::string title, int width, int height);

		void run ();


	private:
		bool m_isRunning;

		std::string m_title;

		int m_width;
		int m_height;

		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

};

namespace obj
{
	struct object
	{
		float (*O) (float, float, float);

		float (*O_x) (float, float, float);
		float (*O_y) (float, float, float);
		float (*O_z) (float, float, float);
	};

	extern std::vector<object> objectList;
	void initObjects ();

	//object function
	float O1 (float x, float y, float z);

	//partial derivatives
	float O1_x (float x, float y, float z);
	float O1_y (float x, float y, float z);
	float O1_z (float x, float y, float z);
}


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

		std::string to_string ()
		{
			return std::string{"vec3{"} + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "}";
		}
	};



	vec3 operator + (vec3 vec1, vec3 vec2);
	vec3 operator - (vec3 vec1, vec3 vec2);
	vec3 operator * (vec3 vec, float sc);
	vec3 operator * (float sc, vec3 vec);
	vec3 operator / (vec3 vec, float sc);

	p3 operator + (p3 pt, vec3 vec);
	p3 operator - (p3 pt, vec3 vec);



	float mod (float a, float b);

	vec3 unitVec (float theta, float phi);
	vec3 unitVec (vec3 from);

	float magnitude (vec3 vec);

	float thetaGet (vec3 vec);
	float phiGet (vec3 vec);

	extern float castIncLen;
	extern float castMaxLen;

	float coordNorm_horiz (uint32_t coord);
	float coordNorm_vert (uint32_t coord);

	struct intersect
	{
		bool defined;
		p3 point;
		size_t objIndex;
	};

	intersect cast (p3 point, vec3 direction, bool doBinSearch);

};

#endif
