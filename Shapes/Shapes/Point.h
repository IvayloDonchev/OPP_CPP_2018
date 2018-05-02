#pragma once
#include <iostream>
class Point
{
public:
	Point();
	Point(double, double);
	~Point() = default;
	double DistanceTo(Point);
	friend std::ostream& operator<<(std::ostream&, const Point&);
private:
	double x, y;
};

