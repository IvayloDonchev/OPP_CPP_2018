#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T buf{move(a)};
	a = (T&&) b;		
	b = (T&&) buf;	
}

class mystring {
	char *buffer;
public:
	mystring() : buffer(nullptr) {
		cout << this << " default constructor...\n";
	}
	mystring(const char* s) {
		size_t sz { strlen(s) + 1 };
		buffer = new char[sz];
		strcpy_s(buffer, sz, s);
		cout << this << " constructor...\n";
	}
	~mystring() {
		cout << this << " destructor...\n";
		if(buffer) delete[] buffer;
	}
	//Copy semantics
	mystring(const mystring& other) //copy constructor
	{
		size_t sz{ strlen(other.buffer) + 1 };
		buffer = new char[sz];
		strcpy_s(buffer, sz, other.buffer);
		cout << this << " copy constructor...\n";
	}
	mystring& operator=(const mystring& other)  //copy assignment
	{
		if (this == &other) return *this;
		if (buffer) delete[] buffer;
		size_t sz{ strlen(other.buffer) + 1 };
		buffer = new char[sz];
		strcpy_s(buffer, sz, other.buffer);
		cout << this << " copy assignment...\n";
		return *this;
	}
	//Move semantics
	mystring(mystring&& other) noexcept :	//move constructor
		buffer(move(other.buffer))
	{
		other.buffer = nullptr;
		cout << this << " move constructor...\n";
	}
	mystring& operator=(mystring&& other) noexcept	//move assignment operator
	{
		if (this == &other) return *this;	//self assignment
		if (buffer) delete[] buffer;
		buffer = std::move(other.buffer);
		other.buffer = nullptr;
		cout << this << " move assignment...\n";
		return *this;
	}
	void disp() const {
		cout << buffer << endl;
	}
	friend ostream& operator << (ostream & out, const mystring & s) {
		return out << s.buffer;
	}
};

int main()
{
	mystring s1("Ivan Ivanov");   
	mystring s2("Petar Petrov");				  
	Swap(s1, s2);
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;

	system("pause");
}
