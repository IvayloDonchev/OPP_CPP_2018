#pragma once
#include <iostream>
#include <cstring>

class mystring {
	char *buffer;
public:
	mystring() : buffer(nullptr) {	// default constructor
		std::cout << this << " default constructor...\n";
	}
	mystring(const char*);					//constructor
	~mystring();							//destructor
	//copy semantics
	mystring(const mystring&);				//copy constructor
	mystring& operator=(const mystring&);	//copy assignment
	//move semantics
	mystring(mystring&&);					//move constructor
	mystring& operator=(mystring&&);		//move assignment
	void disp() const;
	operator char*() {  //операция за преобразуване на типа до char*
		return buffer;
	}
};
//class mystring
//{
//private:
//	char *buf;
//public:
//	mystring() : buf(nullptr)
//	{
//		std::cout << this << " default constructor...\n";
//	}
//	mystring(const char*);
//	~mystring();
//	mystring(const mystring&);
//	mystring& operator=(const mystring&);
//	void disp() const;
//};

