#include <stdexcept>
#include "OutOfRangeException.h"
#include <cmath>
#include <iostream>
using namespace std;

/*    �������� ����� ReadNumber(int start, int end), ����� ������� �� ��������� ����� 
  � ��������� [start � end]. � ������ �� �������� ��������� ����� ��� �����, ����� �� � � ���������
  ��������, �������� ��������� ����������. ����������� ���� �����, �������� ��������, 
  ����� ������� 10 ����� a1, a2, �, a10, ������, �� 1 < a1 < � < a10 < 100.  */

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
	for (int i = 0; i < N; i++)  // ��������� �� �����������
		cout << mas[i] << " ";
	cout << endl;

	/*   �������� ��������, ����� ������� �� ��������� ���� ����������� ����� � ��������� 
	  �� ��������� ����� ��������� �� ���� �����. ��� ������� � ����������� ��� ���������, 
	  �� �� ������ "Invalid Number" �� ���������. ��� ������ ������ �� �� �������� �� ���������
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