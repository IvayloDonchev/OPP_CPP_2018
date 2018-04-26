#include "Deposit.h"

Deposit::Deposit(Client &c, double b, double i) : Account(c, b, i)
{}

void Deposit::WithdrawMoney(double d)
{
	balance -= d;
}
