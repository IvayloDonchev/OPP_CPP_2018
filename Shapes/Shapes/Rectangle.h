#pragma once
#include "Shape.h"

class Rectangle :
	public Shape
{
public:
	Rectangle()=default;
	Rectangle(double, double);
	~Rectangle()=default;
	virtual double Area() override;
	virtual void Disp() override;
private:
	double a, b;
};

