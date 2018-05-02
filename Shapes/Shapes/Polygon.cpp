#include "Polygon.h"

Polygon::Polygon(std::initializer_list<Point> pts) : points(pts)
{
}

double Polygon::Perimeter()
{
	double length = 0.0;
	size_t n = points.size();
	for (size_t i = 0; i < n - 1; i++)
		length += points[i].DistanceTo(points[i + 1]);
	length += points[n - 1].DistanceTo(points[0]);
	return length;
}

double Polygon::Area()
{
	return 0.0;
}

void Polygon::Disp()
{
	std::cout << "Polygon with " << points.size() << " sides "
		<< "and perineter " << Perimeter() << std::endl;
}
