#include "Article.h"
#include "Cooker.h"
#include "Fridge.h"
#include <iostream>
#include <vector>
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
	vector<Article*> v;
	v.push_back(new Cooker("Diplomat", 550, 1000, 4500, 38, 3));
	v.push_back(new Fridge("Beko", 340, 123, 175, 60, 300, true));
	v.push_back(new Cooker("Delonghi", 700, 321, 4000, 30, 4));
	for (int i = 0; i < v.size(); i++)
		v[i]->Show();

	system("pause");
}
