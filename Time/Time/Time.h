#pragma once
#include <iostream>
class Time
{
private:
	int hours;
	int minutes;
	int seconds;
	void Simplify();	//прави времето в коректен вид
public:
	Time();
	Time(int, int, int);
	void SetTime(int = 0, int = 0, int = 0);
	operator int();	//преобразува времето до int
	Time operator+(int);	//добавя секунди към времето
	Time operator-(int);	//изважда секунди от времето
	void operator +=(int);
	void operator -=(int);
	Time operator+(const Time&);	//добавя ч, м, с
	Time operator-(const Time&);    //изважда ч, м, с
	friend std::ostream& operator<<(std::ostream&, const Time&);
	friend std::istream& operator>>(std::istream&, Time&);
};

