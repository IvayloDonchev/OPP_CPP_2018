#include "Account.h"
#include "Client.h"
#include "Credit.h"
#include "Deposit.h"
#include "IndividualClient.h"
#include "CorporateClient.h"
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	Client *cp = new CorporateClient();
	cout << typeid(cp).name() << endl;
	system("pause");
}