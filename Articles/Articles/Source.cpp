#include "Article.h"
#include "Cooker.h"
#include "Fridge.h"
#include <iostream>
using namespace std;

int main()
{
	const int N = 3;
	Article* list[N];
	list[0] = new Cooker("Diplomat", 550, 1000, 4500, 38, 3);
	list[1] = new Fridge("Beko", 340, 123, 175, 60, 300, true);
	list[2] = new Cooker("Delonghi", 700, 321, 4000, 30, 4);
	for (auto a : list)
	{
		a->Show();
		cout << "---------------------------------------------\n";
	}

	system("pause");
}