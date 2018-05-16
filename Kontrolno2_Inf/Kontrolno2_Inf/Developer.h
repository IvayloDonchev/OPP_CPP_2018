#pragma once
#include "Employee.h"
class Developer :
	public Employee
{
public:
	Developer() = default;
	Developer(std::string, int, double, bool, bool);
	virtual ~Developer() = default;
	virtual void ShowInfo() override;
private:
	bool cpp;
	bool java;
};

