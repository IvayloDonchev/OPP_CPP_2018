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
	virtual double Perimeter() const override;
	virtual double Area() const override; 
	virtual void Disp() const override;
private:
	std::vector<Point> points;
};

