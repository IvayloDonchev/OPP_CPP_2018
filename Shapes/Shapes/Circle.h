#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
public:
	Circle()=default;
	~Circle()=default;
	Circle(double);
	virtual double Area() const override;
	virtual double Perimeter() const override;
	virtual void Disp() const override;
private:
	double r;
};

