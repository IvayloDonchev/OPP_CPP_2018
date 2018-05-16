#include "Employee.h"
#include <iostream>

Employee::Employee(std::string n, int i, double s) :
	name(n), internship(i), salary(s)
{}

void Employee::ShowInfo()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Internship: " << internship << " months\n";
	std::cout << "Salary: " << salary << std::endl;
}
