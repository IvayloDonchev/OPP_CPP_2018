#include "mystring.h"
using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T buf = (T&&)a;   //move constructor
	a = (T&&)b;       //move assignment
	b = (T&&)buf;     //move assignment
}

int main()
{
	mystring ms1("Ivan Ivanov");
	mystring ms2("Petar Petrov");
	Swap(ms1, ms2);
	ms1.disp();
	ms2.disp();
	cout << endl;

}