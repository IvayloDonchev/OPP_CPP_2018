#include "mystring.h"

mystring::mystring(const char *b)
{
	size_t sz = strlen(b) + 1;
	buffer = new char[sz];
	strcpy_s(buffer, sz, b);
	std::cout << this << " constructor...\n";
}

mystring::~mystring()
{
	std::cout << this << " destructor...\n";
	if (buffer) delete[] buffer;
}

mystring::mystring(const mystring &other) // copy constructor
{
	size_t sz = strlen(other.buffer) + 1;
	buffer = new char[sz];
	strcpy_s(buffer, sz, other.buffer);
	std::cout << this << " copy constructor...\n";
}

mystring & mystring::operator=(const mystring &other)  //copy assignment
{
	if (this == &other) return *this;
	if (buffer) delete[] buffer;
	size_t sz = strlen(other.buffer) + 1;
	buffer = new char[sz];
	strcpy_s(buffer, sz, other.buffer);
	std::cout << this << " copy assignment...\n";
	return *this;
}

mystring::mystring(mystring &&other) : buffer(nullptr)
{
	*this = std::move(other);
	std::cout << this << " move constructor...\n";
}

mystring& mystring::operator=(mystring &&other)  //move assignment operator
{
	if (this == &other) return *this;
	if (buffer) delete[] buffer;
	buffer = std::move(other.buffer);
	other.buffer = nullptr;
	std::cout << this << " move assignment...\n";
	return *this;
}

void mystring::disp() const
{
	std::cout << buffer << std::endl;
}
