#include "Worker.h"

Worker::Worker():Person(), department(nullptr), salary(0.0)
{}

Worker::Worker(const char *n, int y, const char *d, double s) :
	Person(n,y)
{
	int sz = strlen(d) + 1;
	department = new char[sz];
	strcpy_s(department, sz, d);
	salary = s;
}

Worker::Worker(const Worker &other) : Person(other)
{
	*this = other;
	/*int sz = strlen(other.department) + 1;
	department = new char[sz];
	strcpy_s(department, sz, other.department);
	salary = other.salary;*/
}

Worker & Worker::operator=(const Worker &other)
{
	if (this == &other) return *this;
	Person::operator=(other);
	if (department) delete[] department;
	int sz = strlen(other.department) + 1;
	department = new char[sz];
	strcpy_s(department, sz, other.department);
	salary = other.salary;
	return *this;
}

Worker::Worker(Worker &&other):Person(std::move(other))
{
	//*this = std::move(other);
	department = std::move(other.department);
	salary = std::move(other.salary);
	other.department = nullptr;
	other.salary = 0.0;
}

Worker & Worker::operator=(Worker &&other)
{
	if (this == &other) return *this;
	Person::operator=(std::move(other));
	if (department) delete[] department;
	department = std::move(other.department);
	salary = std::move(other.salary);
	other.department = nullptr;
	other.salary = 0.0;
	return *this;
}

Worker::~Worker()
{
	if(department) delete[] department;
}

std::ostream & operator<<(std::ostream &out, const Worker &w)
{
	out << "------- Worker Info ------- \n";
	out << (const Person&)w << std::endl;
	out << "Department: " << w.department << std::endl;
	out << "Salary: " << w.salary << std::endl;
	return out;
}

std::istream & operator>>(std::istream &ent, Worker &w)
{
	ent >> (Person&)w;
	char buf[50];
	std::cout << "Department: "; ent >> buf;
	if (w.department) delete[] w.department;
	int sz = strlen(buf);
	w.department = new char[sz];
	strcpy_s(w.department, sz, buf);
	std::cout << "Salary: "; ent >> w.salary;
	return ent;
}
