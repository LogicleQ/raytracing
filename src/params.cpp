#include "raytracing.hpp"

using calc::p3;
using calc::anglePair;


//uint32_t win_width = 800;
//uint32_t win_height = 600;

uint32_t win_width = 1200;
uint32_t win_height = 900;


p3 camPos = {-5.5, -2.5, 4};

anglePair camDirection = {(float) (5*pi/20), (float) (-pi/7)};

//angle from center of screen to right edge
float apertureAngle = pi / 4;




//calculation parameters
float calc::binSearchIters = 15;

float calc::castIncLen = 0.1;
float calc::castMaxLen = 50;

uint32_t calc::maxReflections = 7;
