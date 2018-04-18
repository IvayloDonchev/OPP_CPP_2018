#pragma once
class Shape
{
public:
	virtual double Area();
	virtual void Disp();
	Shape()=default;
	~Shape()=default;
};

