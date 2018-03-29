#include "Time.h"
using namespace std;

int main()
{
	Time t1(10, 30, 45);
	Time t2(2, 40, 50);
	cout << t1 - t2 << endl;
	cout << Time(7, 49, 55) + t2 << endl;

	t1 -= 1845;
	cout << "t1 = " << t1 << endl;

	system("pause");
}