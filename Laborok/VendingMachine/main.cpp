#include "VendingMachine.h"

int main()
{
	std::string Cola("Coca-Cola");
	std::string Fanta("Fanta");

	VendingMachine coldDrinkMachine;

	coldDrinkMachine.refill(Cola, 5);
	coldDrinkMachine.print();
    coldDrinkMachine.refill(Fanta, 4);
    coldDrinkMachine.print();
    coldDrinkMachine.buy(3);

    VendingMachine machine2(coldDrinkMachine);
    machine2.print();
    machine2.buy(6);
    machine2.print();
}
