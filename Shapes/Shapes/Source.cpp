#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>
using namespace std;

int main()
{
	const int N = 5;
	Shape* shapes[N];
	shapes[0] = new Triangle(3, 4, 5);
	shapes[1] = new Triangle(7, 3, 5);
	shapes[2] = new Rectangle(2,5);
	shapes[3] = new Circle(7.5);
	shapes[4] = new Circle(1.0);
	//----------------------------------
	for (int i = 0; i < N; i++)
	{
		shapes[i]->Disp();
		cout << "-------------------------\n";
	}
	system("pause");
}