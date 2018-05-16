#include "Manager.h"
#include <iostream>

Manager::Manager(std::string n, int i, double s, int sp) :
	 Employee(n,i,s),
	num_subordinate_employees(sp)
{}

void Manager::ShowInfo()
{
	std::cout << "--- Manager ---\n";
	Employee::ShowInfo();
	std::cout << "Manages " << num_subordinate_employees << " people\n";
}
