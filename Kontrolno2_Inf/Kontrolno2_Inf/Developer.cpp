#include "Developer.h"
#include <iostream>

Developer::Developer(std::string n, int i, double s, bool c, bool j) :
	Employee(n,i,s),
	cpp(c),
	java(j)
{}

void Developer::ShowInfo()
{
	std::cout << "--- Developer ---\n";
	Employee::ShowInfo();
	if (cpp) std::cout << "Knows C++\n";
	if (java) std::cout << "Knows Java\n";
}
