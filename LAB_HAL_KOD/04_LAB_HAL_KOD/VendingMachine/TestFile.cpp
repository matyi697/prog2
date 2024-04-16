#include "VendingMachine.h"

int main()
{
	// kóla definiálása
	std::string Cola("Coca-Cola");

	// TODO másfajta ital(ok) definiálása

	// automata létrehozása
	VendingMachine coldDrinkMachine;	

	// feltöltés 5 Coca-colával
	coldDrinkMachine.refill(Cola, 5);

	// ellenõrzés
	coldDrinkMachine.print();

	// TODO vásárlás és másoló konstruktor kipróbálása, több automata létrehozása
	
}