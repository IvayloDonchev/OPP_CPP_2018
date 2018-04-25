#include "Cooker.h"
#include <iostream>

Cooker::Cooker(std::string brand, double price, int stock, int power, int volume, int plates) :
	Article(brand, price, stock),
	power(power), volume(volume), plates(plates)
{}

void Cooker::Show()
{
	std::cout << "--- Cooker info ---" << std::endl;
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Stock: " << stock << std::endl;
	std::cout << "Power: " << power << std::endl;
	std::cout << "Owen volume: " << volume << std::endl;
	std::cout << "Number of plates: " << plates << std::endl;
}
