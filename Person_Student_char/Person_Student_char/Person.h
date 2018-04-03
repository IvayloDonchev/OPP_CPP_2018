#pragma once
#include <cstring>
#include <iostream>
class Person
{
public:
	Person();							//default constructor
	Person(const char*, int);
	~Person();							//destructor
	Person(const Person&);				//copy constructor
	Person(Person&&);					//move constructor;
	Person& operator=(const Person&);	//copy assignment
	Person& operator=(Person&&);		//move assignment
	friend std::ostream& operator<<(std::ostream&, const Person&);
	friend std::istream& operator>>(std::istream&, Person&);
private:
	char* name;
	int year;
};

