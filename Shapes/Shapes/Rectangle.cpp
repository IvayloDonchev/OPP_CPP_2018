#include "Rectangle.h"
#include <stdexcept>
#include <iostream>

Rectangle::Rectangle(double a, double b) : a(a), b(b)
{
	if ((a <= 0.0) || (b <= 0.0))
		throw std::out_of_range("False rectangle");
}

double Rectangle::Area()
{
	return a*b;
}

void Rectangle::Disp()
{
	std::cout << "Rectangle with sides " << a << ", " << b;
	std::cout << " and area " << Area() << std::endl;
}
