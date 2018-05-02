#pragma once
#include "Shape.h"
class Triangle :
	public Shape
{
public:
	Triangle()=default;
	Triangle(double, double, double);
	~Triangle()=default;
	virtual double Area() override;
	virtual double Perimeter() override;
	virtual void Disp() override;
private:
	double a, b, c;   //страните на триъгълника
};

