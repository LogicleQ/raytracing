#include "raytracing.hpp"

using calc::p3;
using calc::anglePair;


uint32_t win_width = 800;
uint32_t win_height = 600;



p3 camPos = {-6, -2, 3};

anglePair camDirection = {(float) pi/5, (float) (-pi/8)};

//angle from center of screen to right edge
float apertureAngle = pi / 4;




//calculation parameters
float calc::binSearchIters = 15;

float calc::castIncLen = 0.1;
float calc::castMaxLen = 50;
