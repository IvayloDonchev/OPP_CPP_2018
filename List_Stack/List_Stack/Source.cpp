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
	
	Stack st1;
	for (int i = 1; i <= 10; i++)
		st1.push(i);
	Stack st3{ st1 };		//copy constructor
	Stack st2 = move(st1);	//move constructor
	//�� �� ������ ����������, ������ �� ������������ ����� �� ������.
	//� ���� ������ static_cast<List>(st2) �� ������, ������ ������������� � private
	//������ �� �� �������� reinterpret_cast �� �������� ��� List
	cout << "st2: " << *reinterpret_cast<List*>(&st2) << endl;
	cout << "st1: " << *reinterpret_cast<List*>(&st1) << endl; //������ ������
	int x;
	cout << "pop operations...";
	while (st2.pop(x))
		cout << x << ' ';
	cout << endl;
	cout << "st3: " << *reinterpret_cast<List*>(&st3) << endl;
	system("pause");
}