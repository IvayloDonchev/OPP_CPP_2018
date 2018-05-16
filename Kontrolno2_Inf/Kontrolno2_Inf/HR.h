#pragma once
#include <vector>
#include "Employee.h"
class HR
{
public:
	HR() = default;
	~HR() = default;
	void AddNew();
	void FireEmployee(std::string);
	double CalculateExpences();
	void ShowEmployeeList();
private:
	std::vector<Employee*> employees;
};

