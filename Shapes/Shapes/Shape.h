#pragma once
class Shape   //Абстрактен клас
{
public:		//само чисти виртуални методи
	virtual double Area() const = 0;	
	virtual double Perimeter() const = 0;
	virtual void Disp() const =0;	
};

