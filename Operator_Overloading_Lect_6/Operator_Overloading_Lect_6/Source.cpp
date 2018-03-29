#include <iostream>
using namespace std;

class vector {
private:
	double x, y;
public:
	vector(double x, double y) : x(x), y(y) {}
	vector() :x(0), y(0) {}
	void Show() {
		cout << '(' << x << ',' << y << ')';
	}
	vector operator+(const vector& v){
		return vector(x + v.x, y + v.y);
	}
	vector operator-(vector v) {
		return vector(x - v.x, y - v.y);
	}
	friend ostream& operator<<(ostream&, const vector&);
	friend istream& operator>>(istream&, vector&);
};

ostream& operator<<(ostream& out, const vector& v)
{
	out << '(' << v.x << ',' << v.y << ')';
	return out;
}

istream& operator>>(istream& in, vector& v)
{
	cout << "v.x = ";
	in >> v.x;
	cout << "v.y = ";
	in >> v.y;
	return in;
}

int main()
{
	vector V1(10, 20), V2(20, 40);
	vector V3 = V1 + V2; // V3 = V1.operator+(V2);
	cout << V1 << " + " << V2 << " = " << V3 << endl;
	cin >> V1;
	cout << V1 << endl;
	system("pause");
}