#include <iostream>
#include <cstring>
using namespace std;

class mystring {
	char* buffer;
public:
	mystring() : buffer(nullptr)
	{
		cout << this << " default constructor...\n";
	}
	mystring(const char* s) {
		size_t sz = strlen(s) + 1;
		buffer = new char[sz];
		strcpy_s(buffer, sz, s);
		cout << this << " constructor...\n";
	}
	mystring(const mystring& other) {		//copy constructor
		size_t sz = strlen(other.buffer) + 1;
		buffer = new char[sz];
		strcpy_s(buffer, sz, other.buffer);
		cout << this << " copy constructor...\n";
	}
	mystring& operator=(const mystring& other)  //copy assignment
	{
		if (this == &other) return *this;  //self assignment
		if (buffer) delete[] buffer;
		size_t sz = strlen(other.buffer) + 1;
		buffer = new char[sz];
		strcpy_s(buffer, sz, other.buffer);
		cout << this << " copy assignment...\n";
		return *this;	//връща обекта отляво на =
	}
	~mystring()
	{
		cout << this << " destructor...\n";
		if (buffer) delete[] buffer;
	}
	void Show() const {
		cout << buffer << endl;
	}
	void Read() {
		if (buffer) delete[] buffer;
		char buf[80];
		cout << "Enter a string: ";
		cin >> buf;
		size_t sz = strlen(buf) + 1;
		buffer = new char[sz];
		strcpy_s(buffer, sz, buf);
	}
};

void Foo(const mystring &s)
{
	s.Show();
}

void Read(mystring &s)
{
	s.Read();
}

int main()
{
	mystring s1;
	s1.Read();
	Foo(s1);
	//s1.Show();
	//mystring s2{ s1 };	// copy constructor    (копиращ конструктор)
	//mystring s3;		// default constructor
	//s3 = s1;			// copy assignment operator (копиращо присвояване)
	////s3.operator=(s1);   // същото нещо
	//s3.Show();

	
	
}