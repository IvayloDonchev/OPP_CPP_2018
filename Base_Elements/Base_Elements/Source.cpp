#include <iostream>
using namespace std;

constexpr int arrSize()
{
	return (unsigned)time(nullptr);
}

int main()
{
	int i = 20;
	int *ip = &i;
	cout << "*ip = " << *ip << endl;
	*ip = 50;
	cout << "i = " << i << endl;
	cout << "ip = " << ip << endl;
	cout << "&i = " << &i << endl;

	double d;
	double *pd = &d;
	char ch='A';
	char *pch;
	pch = &ch;

	ip = reinterpret_cast<int*>(pch);
	cout << "*ip = " << (char)(*ip) << endl;

	i = (int)(&i);  // в променливата i е записан адреса на i
	cout << hex << "i = " << i << endl;
	ip = reinterpret_cast<int*>(i); // От число получаваме адрес. Сега ip отново сочи i
	cout << "*ip = " << *ip << endl;

	system("pause");




}