#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>
using namespace std;

int main()
{
	Shape* shapes[]{ new Triangle(3, 4, 5), 
		             new Triangle(7, 3, 5), 
		             new Rectangle(2,5),
					 new Circle(7.5),
		             new Circle(1.0) };
	
	for (auto x : shapes)
		x->Disp();

	system("pause");
}