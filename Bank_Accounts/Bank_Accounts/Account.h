#pragma once
#include "Client.h"
class Account			//банкова сметка
{
public:
	Account()=default;
	Account(Client&, double, double);
	~Account()=default;
	void DepositMoney(double); //вн€с€не на пари
	virtual double CalculateInterest(int months) = 0; //изчисл€ване на лихвата
private:
	Client client;		//клиент
	double balance;		//баланс
	double interest;	//месечен лихвен процент
};

