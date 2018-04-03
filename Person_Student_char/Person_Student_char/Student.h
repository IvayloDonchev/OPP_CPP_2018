#pragma once
#include "Person.h"
class Student : public Person
{
public:
	Student()=default;
	~Student();
	Student(const char*, int, int, const char*, int);
	Student(const Student&);
	Student& operator=(const Student&);
	Student(Student&&);
	Student& operator=(Student&&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
private:
	int fn;
	char* program;
	int year;
};

