#include "Employee.h"
#include "Developer.h"
#include "Manager.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<Employee*> employees;
	employees.push_back(new Developer("Ivan", 24, 1500, true, true));
	employees.push_back(new Manager("Petar", 45, 2500, 12));
	for (auto e : employees)
		e->ShowInfo();

	system("pause");
}