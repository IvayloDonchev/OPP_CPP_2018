#pragma once
#include <string>

class Article
{
public:
	Article() = default;
	Article(std::string, double, int);
	~Article() = default;
	virtual void Show() = 0;
protected:
	std::string brand;	//марка
	double price;		//цена
	int stock;			//наличност
};

