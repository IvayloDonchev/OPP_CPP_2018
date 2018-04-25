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
	std::string brand;	//�����
	double price;		//����
	int stock;			//���������
};

