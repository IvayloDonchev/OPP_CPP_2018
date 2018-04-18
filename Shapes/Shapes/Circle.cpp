#include "Circle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <stdexcept>

Circle::Circle(double r) : r(r)
{
	if (r < 0.0)
		throw std::out_of_range("False circle");
}

double Circle::Area()
{
	return M_PI*r*r;
}

void Circle::Disp()
{
	std::cout << "Circle ";
	std::cout << "radius: " << r << std::endl;
	std::cout << "Area: " << Area() << std::endl;
}
