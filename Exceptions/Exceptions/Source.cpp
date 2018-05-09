#include <stdexcept>
#include "OutOfRangeException.h"
#include <cmath>
#include <iostream>
using namespace std;

int ReadNumber(int start, int end)
{
	int x;
	cout << "x = "; cin >> x;
	if (x <= start || x > end)
		throw OutOfRangeException("Incorrect number");
	return x;
}

int main()
{
	const int N = 10;
	int mas[N];
	int i = 0;
	mas[0] = 0;
	int x;
	loop:
	try {
		x = ReadNumber(0, 100);
	}
	catch (OutOfRangeException &e)
	{
		cout << e.what();
		goto loop;
	}
	mas[0] = x;
	while (i < N)
	{
		cout << "Enter a number [" << i << "]: ";
		try {
			x = ReadNumber(mas[i-1], 100);
		}
		catch (OutOfRangeException &e)
		{
			cout << e.what() << endl;
			continue;
		}
		mas[i++] = x;
	}
	for (int i = 0; i < N; i++)
		cout << mas[i] << " ";
	cout << endl;


	/*int n;
	cout << "n = "; cin >> n;
	try {
		if (n < 0)
			throw invalid_argument("Invalid number");
		cout << "sqrt(" << n << ") = " << sqrt(n) << endl;
	}
	catch (invalid_argument &e)
	{
		cout << e.what() << endl;
	}
	cout << "Good bye" << endl;*/

	system("pause");
}