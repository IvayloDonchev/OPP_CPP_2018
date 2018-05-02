#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
public:
	Circle()=default;
	~Circle()=default;
	Circle(double);
	virtual double Area() override;
	virtual double Perimeter() override;
	virtual void Disp() override;
private:
	double r;
};

