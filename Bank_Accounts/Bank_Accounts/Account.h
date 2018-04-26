#pragma once
#include "Client.h"
class Account			//������� ������
{
public:
	Account()=default;
	Account(Client&, double, double);
	~Account()=default;
	void DepositMoney(double); //������� �� ����
	virtual double CalculateInterest(int months) = 0; //����������� �� �������
private:
	Client client;		//������
	double balance;		//������
	double interest;	//������� ������ �������
};

