#include "List.h"
#include <exception>

List::List():top(nullptr)
{}

List::List(Element x):top(new Node(x))
{}

List::List(std::initializer_list<Element> src) //initializer list constructor
{
	top = nullptr;
	for (auto p : src) // range-based for loop
		push_back(p);
}

List::~List()
{
	while (top)
	{
		pList p = top;
		top = top->next;
		delete p;
	}
	top = nullptr;
}

bool List::push_front(Element x)
{
	pList p = new Node(x);
	if (!p) return false;
	p->next = top;
	top = p;
	return true;
}

bool List::push_back(Element x)
{
	pList p = new Node(x);
	if (!p) return false;
	if (!top)	//Ако списъкът е празен
		top = p;
	else
	{
		pList q;
		for (q = top; q->next; q = q->next);
		q->next = p;
	}
	return true;
}

bool List::get_top(Element &e)
{
	if (!top) return false;
	e = top->key;
	return true;
}

bool List::remove_top()
{
	if (!top) return false;
	pList p = top;
	top = top->next;
	delete p;
	return true;
}

bool List::operator+=(Element x)
{
	return push_back(x);
}

Element & List::operator[](int ind)
{
	pList p = top;
	for (int i = 0; p && i < ind; i++)
		p = p->next;
	if (!p)
		throw std::out_of_range("Incorrect index...");
	return p->key;
}

size_t List::size()
{
	size_t len = 0;
	for (pList p = top; p; p = p->next)
		len++;
	return len;
}

List::List(const List &other)
{
	*this = other;
}

List & List::operator=(const List &other)
{
	if (this == &other) return *this;
	this->~List();
	top = new Node(other.top->key);
	pList r = top;
	for (pList p = other.top->next; p; p = p->next)
	{
		pList q = new Node(p->key);
		r->next = q;	// добавяне в края
		r = q;
	}
	return *this;
}

List::List(List &&other)
{
	*this = std::move(other);
}

List & List::operator=(List &&other)
{
	if (this == &other) return *this;
	this->~List();
	top = std::move(other.top);
	other.top = nullptr;
	return *this;
}

std::ostream & operator<<(std::ostream &out, const List &l)
{
	for (List::pList p = l.top; p; p = p->next)
		out << p->key << ' ';
	return out;
}
