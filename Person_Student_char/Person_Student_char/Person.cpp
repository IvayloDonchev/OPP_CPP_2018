#include "Person.h"

Person::Person() : name(nullptr), year(0)
{}

Person::Person(const char *n, int y)
{
	int sz = strlen(n) + 1;
	name = new char[sz];
	strcpy_s(name, sz, n);
	year = y;
}

Person::~Person()
{
	if (name) delete[] name;
}

Person::Person(const Person &other)
{
	int sz = strlen(other.name) + 1;
	name = new char[sz];
	strcpy_s(name, sz, other.name);
	year = other.year;
}

Person::Person(Person &&other) :
	name(std::move(other.name)),
	year(std::move(other.year))
{
	other.name = nullptr;
	other.year = 0;
}

Person & Person::operator=(const Person &other)
{
	if (this == &other) return *this;
	if (name) delete[] name;
	int sz = strlen(other.name) + 1;
	name = new char[sz];
	strcpy_s(name, sz, other.name);
	year = other.year;
	return *this;
}

Person & Person::operator=(Person &&other)
{
	if (this == &other) return *this;
	if (name) delete[] name;
	name = std::move(other.name);
	year = std::move(other.year);
	other.name = nullptr;
	other.year = 0;
	return *this;
}

std::ostream & operator<<(std::ostream &out, const Person &p)
{
	out << p.name << ", " << p.year;
	return out;
}

std::istream & operator>>(std::istream &ent, Person &p)
{
	if (p.name) delete[] p.name;
	char s[25];
	std::cout << "Enter the name of person: ";
	ent.getline(s, 25);
	int sz = strlen(s) + 1;
	p.name = new char[sz];
	strcpy_s(p.name, sz, s);
	std::cout << "Enter the year of birth: ";
	ent >> p.year;
	ent.ignore();
	return ent;
}
