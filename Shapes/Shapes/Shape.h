#pragma once
class Shape   //���������� ����
{
public:		//���� ����� ��������� ������
	virtual double Area() const = 0;	
	virtual double Perimeter() const = 0;
	virtual void Disp() const =0;	
};

