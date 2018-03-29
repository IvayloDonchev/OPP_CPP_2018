#pragma once
#include <iostream>
class Time
{
private:
	int hours;
	int minutes;
	int seconds;
	void Simplify();	//����� ������� � �������� ���
public:
	Time();
	Time(int, int, int);
	void SetTime(int = 0, int = 0, int = 0);
	operator int();	//����������� ������� �� int
	Time operator+(int);	//������ ������� ��� �������
	Time operator-(int);	//������� ������� �� �������
	void operator +=(int);
	void operator -=(int);
	Time operator+(const Time&);	//������ �, �, �
	Time operator-(const Time&);    //������� �, �, �
	friend std::ostream& operator<<(std::ostream&, const Time&);
	friend std::istream& operator>>(std::istream&, Time&);
};

