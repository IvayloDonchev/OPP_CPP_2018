#include "Account.h"


Account::Account(Client & c, double b, double i) :
	client(c), balance(b), interest(i)
{}

void Account::DepositMoney(double d)
{
	balance += d;
}
