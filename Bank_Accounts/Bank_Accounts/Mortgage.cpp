#include "Mortgage.h"

Mortgage::Mortgage(Client &c, double b, double i) : Account(c,b,i)
{}

void Mortgage::WithdrawMoney(double d)
{
	balance -= d;
}
