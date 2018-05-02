#pragma once
class Shape   //Абстрактен клас
{
public:		//само чисти виртуални методи
	virtual double Area()=0;	
	virtual double Perimeter() = 0;
	virtual void Disp()=0;	
};

