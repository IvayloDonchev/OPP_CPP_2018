#pragma once
#include "Account.h"
#include "Client.h"
class Deposit :
	public Account
{
public:
	Deposit()=default;
	Deposit(Client&, double, double);
	~Deposit()=default;
	void WithdrawMoney(double);
	double CalculateInterest(int months) override;
};

