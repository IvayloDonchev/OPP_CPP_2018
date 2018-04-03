#include "Person.h"
#include "Student.h"
using namespace std;

int main()
{
	Student s1("Ivan Ivanov", 2000, 18001, "Informatics", 1);
	cout << s1 << endl;
	Student s2;
	s2 = s1;
	cout << s2;
	cin >> s1;
	Student s3 = move(s1);
	cout << s3 << endl;

	system("pause");
}