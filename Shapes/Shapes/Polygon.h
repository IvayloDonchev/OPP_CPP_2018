#pragma once
#include "Shape.h"
#include "Point.h"
#include <initializer_list>
#include <vector>
class Polygon :
	public Shape
{
public:
	Polygon() = default;
	Polygon(std::initializer_list<Point>);
	~Polygon() = default;
	virtual double Perimeter() override;
	virtual double Area() override; // Not implemented (returns 0)
	virtual void Disp() override;
private:
	std::vector<Point> points;
};

