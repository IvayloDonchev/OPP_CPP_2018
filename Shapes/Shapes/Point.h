#pragma once
#include <iostream>
struct Point
{
	double x, y;
	Point();
	Point(double, double);
	~Point() = default;
	double DistanceTo(Point) const;
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

