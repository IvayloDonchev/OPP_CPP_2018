#include "HR.h"
#include "Manager.h"
#include "Developer.h"
#include <iostream>
#include <algorithm>
void HR::AddNew()
{
	std::cout << "--- Add new employee menu ---\n";
	std::cout << "1. Manager\n2. Developer\n";
	int c;
	std::string name;
	int internship;
	double salary;
	int num_employees;
	bool cpp, java;
	char language;
	std::cin >> c;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter internship in monthsL ";
	std::cin >> internship;
	std::cout << "Enter salary: ";
	std::cin >> salary;
	switch (c) {
	case 1: 
		std::cout << "Enter number of employees: ";
		std::cin >> num_employees;
		employees.push_back(new Manager(name, internship, salary, num_employees));
		break;
	case 2:
		std::cout << "C++ (y/n): ";
		std::cin >> language;
		cpp = language == 'y';
		std::cout << "Java (y/n): ";
		std::cin >> language;
		java = language == 'y';
		employees.push_back(new Developer(name, internship, salary, cpp, java)); break;
	}
}
void HR::FireEmployee(std::string n)
{
	auto pos = begin(employees);
	for (; (*pos)->name != n; ++pos);
	if (pos != end(employees))
		employees.erase(pos);
}
double HR::CalculateExpences()
{
	double sum = 0.0;
	for (auto e : employees)
		sum += e->salary;
	return sum;
}
void HR::ShowEmployeeList()
{
	for (auto e : employees)
		e->ShowInfo();
	std::cout << std::endl;
}
