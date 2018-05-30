#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"
#include <iostream>
using namespace std;


void Foo(Shape& s)
{
	cout << s.Area() << endl;
}

int main()
{
	Shape* shapes[]{ new Triangle(3, 4, 5),
					 new Triangle(7, 3, 5),
					 new Rectangle(2,5),
					 new Circle(7.5),
					 new Circle(1.0),
					 new Polygon({Point(2,0), Point(4,0), Point(5,1), Point(4,2), Point(2,2), Point(1,1)}),
					 new Polygon({Point(0,0), Point(3,0), Point(0,4)}),
		             new Polygon({Point(1,0), Point(5,0), Point(5,2), Point(1,2)})
	};
	
	for (auto x : shapes)
		x->Disp();
	//Shape s; //грешка! (обект на абстрактен клас)
	Triangle tri(3, 4, 5);
	Foo(tri);
	system("pause");
}