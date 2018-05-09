#include <stdexcept>
#include "OutOfRangeException.h"
#include <cmath>
#include <iostream>
using namespace std;

/*    Напишете метод ReadNumber(int start, int end), който въвежда от конзолата число 
  в диапазона [start … end]. В случай на въведено невалидно число или число, което не е в подадения
  диапазон, хвърлете подходящо изключение. Използвайки този метод, напишете програма, 
  която въвежда 10 числа a1, a2, …, a10, такива, че 1 < a1 < … < a10 < 100.  */

int ReadNumber(int start, int end)
{
	int x;
	cout << "x = "; cin >> x;
	if (x < start || x > end)
		throw OutOfRangeException("Incorrect number");
	return x;
}

int main()
{
	const int N = 10;
	int mas[N];
	int i = 0;
	int left = 1, right = 100;
	do {
		cout << "[" << i << "] Enter a number between " << left+1 << " and " << right-N+i << ": ";
		try {
			mas[i++] = ReadNumber(left+1, right-N+i);
			left = mas[i - 1];
		}
		catch (OutOfRangeException &e)
		{
			cout << e.what() << endl;
		}
	} while (i < N);
	for (int i = 0; i < N; i++)  // Извеждане на резултатите
		cout << mas[i] << " ";
	cout << endl;

	/*   Напишете програма, която прочита от конзолата цяло положително число и отпечатва 
	  на конзолата корен квадратен от това число. Ако числото е отрицателно или невалидно, 
	  да се изпише "Invalid Number" на конзолата. Във всички случаи да се принтира на конзолата
	  "Good Bye".	*/

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