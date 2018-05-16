#include "HR.h"
#include <iostream>
double HR::CalculateExpences()
{
	double sum = 0.0;
	for (auto e : employees)
		sum += e->salary;
}
void HR::ShowEmployeeList()
{
	for (auto e : employees)
		e->ShowInfo();
	std::cout << std::endl;
}
