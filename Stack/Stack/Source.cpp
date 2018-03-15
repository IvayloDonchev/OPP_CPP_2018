#include <iostream>
using namespace std;

class Stack
{
private:
	struct Node
	{
		int key;
		Node *next;   //�������� ��� ������� �������
		Node() : key(0), next(nullptr) {}
		Node(int x) : key(x), next(nullptr) {}
		void Show() {
			cout << key;
		}
	};
	typedef Node* PNode;	//������ Node* �� ����� PNode
	PNode sp;	            //���� ������ ������� �� ����� (�����)
public:
	Stack() : sp(nullptr) {}
	~Stack() {
		if (sp)	//��� ������ �� � ������
		{
			PNode p = sp;
			while (sp)
			{
				p = sp;
				sp = sp->next;
				delete p;
			}
		}
	}
	Stack(const Stack& other){
		size_t n = const_cast<Stack&>(other).Length();	//���� �� ���������� �� �����
		int *buf = new int[n];
		size_t i = 0;
		for (PNode p = other.sp; p; p = p->next, i++)
			buf[i] = p->key;
		sp = nullptr;
		for (size_t j = n; j > 0; j--)
			Push(buf[j]);
		delete[] buf;
	}
	Stack& operator=(const Stack& other) {
		//-------------------------
	}
	bool Push(int x) {    //�������� �� ������� ��� �����
		if (!sp) {	      //��� ������ � ������
			sp = new Node(x);
			return sp != nullptr;
		}
		else              //� ����� ��� ��������
		{
			PNode p = new Node(x);
			if (!p) return false;
			p->key = x;
			p->next = sp;
			sp = p;
			return true;
		}	
	}
	bool Pop(int &x) {
		if (!sp)		//��� ������ � ������
			return false; //��������� ��������
		PNode p = sp;	//�������� ������� ������� �� ����� �� �����
		x = sp->key;
		sp = sp->next;	//��������� ����� ��� ��������� �������
		delete p;		//������� ������ ����
		return true;    //������� ��������� �� ������� �� �����
	}
	size_t Length() {	//���� �� ���������� � �����
		size_t n = 0;
		for (PNode p = sp; p; p = p->next) //���������
			n++;
		return n;
	}
};

int main()
{
	Stack stack;
	for (int i = 1; i <= 10; i++)
		stack.Push(i);
	cout << "Length: " << stack.Length() << " elements\n";

	Stack st2 = stack;  //copy constructor
	int k;
	while (stack.Pop(k))
		cout << k << " ";
	cout << endl;
	while (st2.Pop(k))
		cout << k << " ";
	cout << endl;

	system("pause");
}