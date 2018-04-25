#pragma once
#include "Article.h"
class Cooker :
	public Article
{
public:
	Cooker() = default;
	Cooker(std::string, double, int, int, int, int);
	~Cooker() = default;
	virtual void Show() override;
private:
	int power;	//обща мощност
	int volume;	//обем на фурната
	int plates;	//брой котлони
};

