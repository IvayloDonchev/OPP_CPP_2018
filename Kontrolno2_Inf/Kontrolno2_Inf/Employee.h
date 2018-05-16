#pragma once
#include <string>
class Employee
{
public:
	Employee() = default;
	Employee(std::string, int, double);
	virtual ~Employee() = default;
	virtual void ShowInfo();
private:
	std::string name;
	int internship;   //������ ���� � ������
	double salary;	  //�������
};

