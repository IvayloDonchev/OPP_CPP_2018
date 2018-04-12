#pragma once
#include "List.h"

class Stack : private List
{
public:
	bool push(Element);
	bool pop(Element&);
};

