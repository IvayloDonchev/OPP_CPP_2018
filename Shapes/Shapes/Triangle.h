#pragma once
#include "Shape.h"
class Triangle :
	public Shape
{
public:
	Triangle()=default;
	Triangle(double, double, double);
	~Triangle()=default;
	virtual double Area() const override;
	virtual double Perimeter() const override;
	virtual void Disp() const override;
private:
	double a, b, c;   //страните на триъгълника
};

