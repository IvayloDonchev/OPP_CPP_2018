#pragma once
#include "Person.h"
class Worker :
	public Person
{
	char* department;		//�����
	double salary;			//�������
public:
	Worker();
	Worker(const char*, int, const char*, double);
	Worker(const Worker&);
	Worker& operator=(const Worker&);
	Worker(Worker&&);
	Worker& operator=(Worker&&);
	~Worker();
	friend std::ostream& operator<<(std::ostream&, const Worker&);
	friend std::istream& operator>>(std::istream&, Worker&);
};

