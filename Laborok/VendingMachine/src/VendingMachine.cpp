#include "VendingMachine.h"
#include <cstdio>

VendingMachine::VendingMachine()
{
	drinkNumber = 0;
	drinks = nullptr;
}

VendingMachine::VendingMachine(const VendingMachine & other)
{
    drinkNumber = other.drinkNumber;
    std::string* newDrink = new std::string[other.drinkNumber];
    for (int i = 0; i < other.drinkNumber; i++)
        newDrink[i] = other.drinks[i];
    drinks = newDrink;
}

int VendingMachine::getDrinkNumber()
{
	return drinkNumber;
}

VendingMachine::~VendingMachine()
{
	delete[] drinks;
}

std::string VendingMachine::removeOne()
{
	if (drinkNumber <= 0)
		return "Empty";

	std::string value = drinks[0];
	std::string* tmp;
	tmp = new std::string[drinkNumber - 1];

	for (int i = 1; i < drinkNumber; i++)
		tmp[i-1] = drinks[i];

	drinkNumber = drinkNumber - 1;
	delete[] drinks;
	drinks = tmp;
	return value;
}

bool VendingMachine::buy(int num)
{
	if (num > drinkNumber)
		return false;
	for (int i = 0; i < num; i++)
	{
		printf("Vasarolt ital: %s\n", removeOne().c_str());
	}
	return true;

}

bool VendingMachine::refill(std::string pName, int pQty)
{
    if (pQty <= 0)
        return false;
    std::string* newDrinks = new std::string[drinkNumber + pQty];

    for(int i = 0; i < drinkNumber; i++)
        newDrinks[i] = drinks[i];

    for (int i = drinkNumber; i < drinkNumber + pQty; i++)
        newDrinks[i] = pName;

    drinkNumber += pQty;
    delete[] drinks;
    drinks = newDrinks;
    return true;
}


void VendingMachine::print()
{
	printf("Keszlet: %d\n", drinkNumber);
	for (int i = 0; i < drinkNumber; i++)
		printf("%s\n", drinks[i].c_str());
	printf("---Lista vege---\n\n");
}


