#include "Stack.h"



bool Stack::push(Element x)
{
	return push_front(x);
}

bool Stack::pop(Element &e)
{
	if (get_top(e)) {
		remove_top();
		return true;
	}
	return false;
}

Stack::Stack()
{
}


Stack::~Stack()
{
}
