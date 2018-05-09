#pragma once
#include <stdexcept>
class OutOfRangeException : public std::runtime_error
{
public:
	OutOfRangeException(const char*);
	~OutOfRangeException();
};

