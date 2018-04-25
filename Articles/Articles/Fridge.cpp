#include "Fridge.h"
#include <iostream>

Fridge::Fridge(std::string brand, double price, int stock, int height, int width, int volume, bool freezer) :
	Article(brand, price, stock),
	height(height), width(width), volume(volume), freezer(freezer)
{}

void Fridge::Show()
{
	std::cout << "--- Fridge info ---" << std::endl;
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Stock: " << stock << std::endl;
	std::cout << "Dimensions: " << height << " x " << width << std::endl;
	std::cout << "Volume: " << volume << std::endl;
	if (freezer)
		std::cout << "Has freezer\n";
	else
		std::cout << "No freezer\n";
}
