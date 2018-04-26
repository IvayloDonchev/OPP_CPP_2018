#pragma once
#include "Account.h"
class Credit :
	public Account
{
public:
	Credit() = default;
	Credit(Client&, double, double);
	~Credit() = default;
	void WithdrawMoney(double);
	double CalculateInterest(int months) override;
};

