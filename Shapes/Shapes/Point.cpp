#include "Point.h"
#include <cmath>
#include <iostream>


Point::Point() : x(0.0), y(0.0)
{}

Point::Point(double x, double y) : x(x), y(y)
{}

double Point::DistanceTo(Point p) const
{
	return sqrt(pow(p.x-x,2)+pow(p.y-y,2));
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << '(' << p.x << ',' << p.y << ')';
	return out;
}
