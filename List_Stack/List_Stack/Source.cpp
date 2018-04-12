#include "List.h"
#include "Stack.h"
using namespace std;

int main()
{
	/*List list;
	for (int i = 1; i <= 10; i++)
		list.push_back(i);
	cout << list << endl;

	list[2] = 100;
	cout << list << endl;*/
	
	Stack st;
	for (int i = 1; i <= 10; i++)
		st.push(i);
	int x;
	while (st.pop(x))
		cout << x << ' ';
	cout << endl;

	system("pause");
}