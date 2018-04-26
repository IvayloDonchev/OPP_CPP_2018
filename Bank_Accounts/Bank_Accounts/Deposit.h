#pragma once
#include "Account.h"
class Deposit :
	public Account
{
public:
	Deposit()=default;
	~Deposit()=default;
	void WithdrawMoney(double);
	double CalculateInterest(int months) override;
};

