#pragma once
#include "Account.h"
class Mortgage :
	public Account
{
public:
	Mortgage() = default;
	Mortgage(Client&, double, double);
	~Mortgage() = default;
	void WithdrawMoney(double);
	double CalculateInterest(int months) override;
};

