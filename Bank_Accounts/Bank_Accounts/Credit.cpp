#include "Credit.h"

Credit::Credit(Client &c, double b, double i) : Account(c, b, i)
{}

void Credit::WithdrawMoney(double d)
{
	balance -= d;
}
