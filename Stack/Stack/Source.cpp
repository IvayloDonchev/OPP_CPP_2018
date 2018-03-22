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
	Stack(const Stack& other){ //copy constructor
		*this = other;
		//int n = const_cast<Stack&>(other).Length();	//брой на елементите на стека
		//int *buf = new int[n];
		//int i = 0;
		//for (PNode p = other.sp; p; p = p->next)
		//	buf[i++] = p->key;
		//for (int i = n - 1; i >= 0; i--)
		//	Push(buf[i]);
		//delete[] buf;
	}
	Stack& operator=(const Stack& other) {
		if (this == &other) return *this;
		if (sp) this->~Stack();
		int n = const_cast<Stack&>(other).Length();
		int *buf = new int[n];
		int i = 0;
		for (PNode p = other.sp; p; p = p->next)
			buf[i++] = p->key;
		for (i = n - 1; i >= 0; i--)
			Push(buf[i]);
		delete[] buf;
		return *this;
	}
	Stack& operator=(Stack&& other) {  //move assignment operator
		if (this == &other) return *this;
		if (sp) this->~Stack();
		sp = std::move(other.sp);
		other.sp = nullptr;
		return *this;
	}
	Stack(Stack&& other) {			//move constructor
		*this = std::move(other);
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

	Stack st2;    //default constructor
	st2 = std::move(stack); //move assignment
	cout << "Length: " << stack.Length() << " elements\n";   // 0
	int k;
	while (st2.Pop(k))
		cout << k << " ";
	cout << endl;
	
	//Stack st2 = stack;  //copy constructor
	//Stack st3;
	//st3.Push(234234);
	//st3.Push(4321);
	//st3 = st2;   //copy assignment
	//int k;
	//while (stack.Pop(k))
	//	cout << k << " ";
	//cout << endl;
	//while (st2.Pop(k))
	//	cout << k << " ";
	//cout << endl;

	//while (st3.Pop(k))
	//	cout << k << " ";
	//cout << endl;

	system("pause");
}