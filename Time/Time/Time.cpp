#include "Time.h"

Time::Time() : hours(0), minutes(0)
{}

Time::Time(int h, int m) : hours(h), minutes(m)
{
	Simplify();
}

void Time::SetTime(int h, int m)
{
	hours = h;
	minutes = m;
	Simplify();
}

Time::operator int()
{
	return hours * 60 + minutes;
}

Time Time::operator+(int m)
{
	return Time(hours, minutes+m);
}

Time Time::operator-(int m)
{
	return Time(hours, minutes - m);
}

void Time::operator+=(int m)
{
	SetTime(hours, minutes + m);
}

void Time::operator-=(int m)
{
	SetTime(hours, minutes - m);
}

Time Time::operator+(const Time &t)
{
	return Time(hours + t.hours, minutes + t.minutes);
}

Time Time::operator-(const Time &t)
{
	return Time(hours - t.hours, minutes - t.minutes);
}

void Time::Simplify()
{
	int m = hours * 60 + minutes;
	hours = m / 60;
	minutes = m % 60;
}

std::ostream & operator<<(std::ostream &out, const Time &t)
{
	out << t.hours << ':' << t.minutes;
	return out;
}

std::istream & operator>>(std::istream &in, Time &t)
{
	std::cout << "hours: "; in >> t.hours;
	std::cout << "minutes: "; in >> t.minutes;
	return in;
}


