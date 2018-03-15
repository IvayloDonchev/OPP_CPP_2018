#include <iostream>
using namespace std;

class Stack
{
private:
	struct Node
	{
		int key;
		Node *next;   //указател към следващ елемент
		Node() : key(0), next(nullptr) {}
		Node(int x) : key(x), next(nullptr) {}
		void Show() {
			cout << key;
		}
	};
	typedef Node* PNode;	//вместо Node* ще пишем PNode
	PNode sp;	            //сочи първия елемент на стека (върха)
public:
	Stack() : sp(nullptr) {}
	~Stack() {
		if (sp)	//ако стекът не е празен
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
		size_t n = const_cast<Stack&>(other).Length();	//брой на елементите на стека
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
	bool Push(int x) {    //добавяне на елемент към стека
		if (!sp) {	      //ако стекът е празен
			sp = new Node(x);
			return sp != nullptr;
		}
		else              //в стека има елементи
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
		if (!sp)		//ако стекът е празен
			return false; //неуспешна операция
		PNode p = sp;	//запазвам старата позиция на върха на стека
		x = sp->key;
		sp = sp->next;	//премества върха към следващия елемент
		delete p;		//изтрива стария връх
		return true;    //успешно извличане на елемент от стека
	}
	size_t Length() {	//брой на елементите в стека
		size_t n = 0;
		for (PNode p = sp; p; p = p->next) //обхождане
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