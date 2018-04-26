#pragma once
#include "Account.h"
class Mortgage :
	public Account
{
public:
	Mortgage();
	~Mortgage();
	double CalculateInterest(int months) override;
};

