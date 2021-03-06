#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T buf{ move(a) };
	a = (T&&)b;
	b = move(buf);	
}

class mystring {
	char* buffer;
public:
	mystring() : buffer{ nullptr } 
	{
		cout << this << " default constructor...\n";
	}
	mystring(const char* s)
	{
		size_t sz{ strlen(s) + 1 };
		buffer = new char[sz];
		strcpy_s(buffer, sz, s);
		cout << this << " constructor...\n";
	}
	~mystring()
	{
		cout << this << " destructor...";
		if (buffer)
			delete[] buffer;
		else
			cout << " (Nothing to delete...)";
		cout << '\n';
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
		if (this == &other)
			return *this;
		if (buffer)
			delete[] buffer;
		size_t sz{ strlen(other.buffer) + 1 };
		buffer = new char[sz];
		strcpy_s(buffer, sz, other.buffer);
		cout << this << " copy assignment...\n";
		return *this;
	}
	//Move semantics
	mystring(mystring&& other) noexcept :	//move constructor
		buffer{ move(other.buffer) }
	{
		other.buffer = nullptr;
		cout << this << " move constructor...\n";
	}
	mystring& operator=(mystring&& other) noexcept	//move assignment operator
	{
		if (this == &other) return *this;	//self assignment
		if (buffer)
			delete[] buffer;
		buffer = std::move(other.buffer);
		other.buffer = nullptr;
		cout << this << " move assignment...\n";
		return *this;
	}
	void disp() const
	{
		if(buffer)
			cout << buffer << endl;
	}
	friend ostream& operator << (ostream& out, const mystring& s)
	{
		if (s.buffer)
			out << s.buffer;
		else
			out << "---empty---";
		return out;
	}
};

int main()
{
	mystring s1("Ivan Ivanov");
	mystring s2("Petar Petrov");
	cout << "---------------Swap----------------\n";
	Swap(s1, s2);
	cout << "---------------Swap----------------\n";
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	mystring s3;
	s3 = s1;
	cout << "s3: " << s3 << endl;
	s2 = move(s3);
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
}
