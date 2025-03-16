#ifndef RAYTRACING_HPP
#define RAYTRACING_HPP

#include <string>
#include <vector>

#include <SDL3/SDL.h>

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



	extern vec3 operator + (vec3 vec1, vec3 vec2);
	extern vec3 operator - (vec3 vec1, vec3 vec2);
	extern vec3 operator * (vec3 vec, float sc);
	extern vec3 operator * (float sc, vec3 vec);
	extern vec3 operator / (vec3 vec, float sc);



	vec3 unitVec (float theta, float phi);
	vec3 unitVec (vec3 from);

	float magnitude (vec3 vec);

	p3 cast (p3 point, vec3 direction, bool doBinSearch);

};

#endif
