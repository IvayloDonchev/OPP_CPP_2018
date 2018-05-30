#include "Circle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <stdexcept>

Circle::Circle(double r) : r(r)
{
	if (r <= 0.0)
		throw std::out_of_range("False circle");
}

double Circle::Area() const
{
	return M_PI*r*r;
}

double Circle::Perimeter() const
{
	return 2 * r * M_PI;
}

void Circle::Disp() const
{
	std::cout << "Circle with radius " << r << " and area " << Area() << std::endl;
}
