#include "Employee.h"
#include "Developer.h"
#include "Manager.h"
#include "HR.h"
#include <iostream>
using namespace std;

int main()
{
	HR hr;
	const int N = 3;
	for (int i = 1; i <= N; i++)
		hr.AddNew();
	hr.ShowEmployeeList();
	cout << endl << "Salary Expenses: " << hr.CalculateExpences() << endl;
	hr.FireEmployee("Ivan");
	cout << "\nAfter fireing Ivan: \n";
	hr.ShowEmployeeList();

	system("pause");
}