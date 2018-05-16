#pragma once
#include "Employee.h"
class Manager :
	public Employee
{
public:
	Manager() = default;
	Manager(std::string, int, double, int);
	virtual void ShowInfo() override;
	virtual ~Manager() = default;
private:
	int num_subordinate_employees;	//брой подчинени служители
};

