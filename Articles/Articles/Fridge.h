#pragma once
#include "Article.h"
class Fridge :
	public Article
{
public:
	Fridge() = default;
	Fridge(std::string, double, int, int, int, int, bool);
	~Fridge() = default;
	virtual void Show() override;
private:
	int height;
	int width;
	int volume;
	bool freezer;
};

