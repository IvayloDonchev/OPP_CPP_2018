#include "Student.h"

Student::~Student()
{
	if (program) delete[] program;
}

Student::Student(const char *n, int y, int f, const char *p, int c):
	Person(n,y)
{
	fn = f;
	int sz = strlen(p) + 1;
	program = new char[sz];
	strcpy_s(program, sz, p);
	year = c;
}

Student::Student(const Student &other) : Person(other)
{
	fn = other.fn;
	int sz = strlen(other.program) + 1;
	program = new char[sz];
	strcpy_s(program, sz, other.program);
	year = other.year;
}

Student & Student::operator=(const Student &other)
{
	if (this == &other) return *this;
	Person::operator=(other);
	fn = other.fn;
	int sz = strlen(other.program) + 1;
	program = new char[sz];
	strcpy_s(program, sz, other.program);
	year = other.year;
	return *this;
}

Student::Student(Student &&other) :Person(std::move(other))
{
	fn = std::move(other.fn);
	program = std::move(other.program);
	year = std::move(other.year);
	other.fn = 0;
	other.program = nullptr;
	other.year = 0;
}

Student & Student::operator=(Student &&other)
{
	if (this == &other) return *this;
	Person::operator=(std::move(other));
	fn = std::move(other.fn);
	if (program) delete[] program;
	program = std::move(other.program);
	year = std::move(other.year);
	other.fn = 0;
	other.program = nullptr;
	other.year = 0;
	return *this;
}

std::ostream & operator<<(std::ostream &out, const Student &s)
{
	out << "------- Student Info ------- \n";
	out << (const Person&)s << std::endl;
	out << "Faculty number: " << s.fn << std::endl;
	out << "Program: " << s.program << std::endl;
	out << "Course: " << s.year << std::endl;
	return out;
}

std::istream & operator>>(std::istream &ent, Student &s)
{
	ent >> (Person&)s;
	std::cout << "Enter faculty number: ";
	ent >> s.fn;
	std::cout << "Enter program: ";
	char buf[50];
	ent >> buf;
	if (s.program) delete[] s.program;
	int sz = strlen(buf);
	s.program = new char[sz];
	strcpy_s(s.program, sz, buf);
	std::cout << "Enter year of study: ";
	ent >> s.year;
	return ent;
}
