#include "Time.h"
#include <iomanip>

Time::Time() : hours(0), minutes(0), seconds(0)
{}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
{
	Simplify();
}

void Time::SetTime(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
	Simplify();
}

Time::operator int()
{
	return hours * 3600 + minutes*60 + seconds;
}

Time Time::operator+(int s)
{
	return Time(hours, minutes, seconds+s);
}

Time Time::operator-(int s)
{
	return Time(hours, minutes, seconds+s);
}

void Time::operator+=(int s)
{
	SetTime(hours, minutes, seconds+s);
}

void Time::operator-=(int s)
{
	SetTime(hours, minutes, seconds-s);
}

Time Time::operator+(const Time &t)
{
	return Time(hours + t.hours, minutes + t.minutes, seconds+t.seconds);
}

Time Time::operator-(const Time &t)
{
	return Time(hours - t.hours, minutes - t.minutes, seconds-t.seconds);
}

void Time::Simplify()
{
	int s = hours * 3600 + minutes * 60 + seconds;
	hours = s / 3600;
	minutes = (s - (hours * 3600)) / 60;
	seconds = s % 60;
}

std::ostream & operator<<(std::ostream &out, const Time &t)
{
	out.setf(std::ios::fixed | std::ios::showpoint);
	out.precision(2);
	out << std::setfill('0') << std::setw(2) << t.hours << ':' 
		<< std::setfill('0') << std::setw(2) << t.minutes << ':' 
		<< std::setfill('0') << std::setw(2) << t.seconds;
	return out;
}

std::istream & operator>>(std::istream &in, Time &t)
{
	std::cout << "hours: "; in >> t.hours;
	std::cout << "minutes: "; in >> t.minutes;
	std::cout << "seconds: "; in >> t.seconds;
	return in;
}


