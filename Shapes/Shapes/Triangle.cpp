#include "Triangle.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c)
{
	if ((a < 0.0) || (b < 0.0) || (c < 0.0) ||
		(a + b <= c) || (a + c <= b) || (b + c <= a))
		throw std::out_of_range("False triangle");
}

double Triangle::Area()
{
	double p = (a + b + c) / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

void Triangle::Disp()
{
	std::cout << "Triangle with sides " << a << ", " << b << ", " << c;
	std::cout << " and area " << Area() << std::endl;
}
