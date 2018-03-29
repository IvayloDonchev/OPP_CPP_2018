#include "Time.h"
using namespace std;

int main()
{
	Time t1(6, 0);
	Time t2(2, 10);
	
	cout << t1-t2 << endl;

	t1.SetTime(5, 30);
	cout << "t1 = " << t1 << endl;

	system("pause");
}