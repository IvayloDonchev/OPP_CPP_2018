#pragma once
#include <string>
class Employee
{
	friend class HR;
public:
	Employee() = default;
	Employee(std::string, int, double);
	virtual ~Employee() = default;
	virtual void ShowInfo();
private:
	std::string name;
	int internship;   //трудов стаж е месеци
	double salary;	  //заплата
};

