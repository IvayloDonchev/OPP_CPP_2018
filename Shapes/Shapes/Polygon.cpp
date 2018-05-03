#include "Polygon.h"

Polygon::Polygon(std::initializer_list<Point> pts) : points(pts)
{
}

double Polygon::Perimeter() const
{
	double length = 0.0;
	size_t n = points.size();
	for (size_t i = 0; i < n - 1; i++)
		length += points[i].DistanceTo(points[i + 1]);
	length += points[n - 1].DistanceTo(points[0]);
	return length;
}

double Polygon::Area() const
{
	double a = 0.0;
	size_t n = points.size();
	for (size_t i = 0; i < n - 1; i++)
		a += (points[i].x - points[i + 1].x) * (points[i].y + points[i + 1].y);
	if (n > 1)
		a += (points[n - 1].x - points[0].x) * (points[n - 1].y + points[0].y);
	return fabs(a / 2);
}

void Polygon::Disp() const
{
	std::cout << "Polygon with " << points.size() << " sides"
		<< ", perineter " << Perimeter()
		<< " and area " << Area() << std::endl;
}
