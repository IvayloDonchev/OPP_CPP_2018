#pragma once
#include "Shape.h"

class Rectangle :
	public Shape
{
public:
	Rectangle() = default;
	Rectangle(double, double);
	~Rectangle() = default;
	virtual double Area() const override;
	virtual double Perimeter() const override;
	virtual void Disp() const override;
private:
	double a, b;
};

