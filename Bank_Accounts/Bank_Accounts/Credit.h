#pragma once
#include "Account.h"
class Credit :
	public Account
{
public:
	Credit();
	~Credit();
	double CalculateInterest(int months) override;
};

