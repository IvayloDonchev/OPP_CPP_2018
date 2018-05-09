#include "OutOfRangeException.h"



OutOfRangeException::OutOfRangeException(const char* what_arg) : 
	   runtime_error(what_arg)
{}


OutOfRangeException::~OutOfRangeException()
{}
