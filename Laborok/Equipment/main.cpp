#include <iostream>
#include "display.h"
#include "printer.h"
#include "equipment.h"

using namespace std;

int main()
{
	const unsigned maxEquipment = 4;

    Equipment* equipmentArray[maxEquipment];

	//Itt hozzunk létre 4 eszközt, az alábbi kimenetek meghatározzák a paramétereiket.
	//Heterogén kollekcióban akarjuk őket tárolni (közös tömbben)

	/************************Elvárt kimenet**************************\
	 Serial Number:1 Price:200 HUF
	 Serial Number:2 Price:12000 HUF Cartridge Price (Printer):12000
	 Serial Number:3 Price:2000 HUF Age (Display): 6
	 Serial Number:4 Price:312000 HUF Cartridge Price (Printer):51000
	\****************************************************************/
	for (int i = 0; i < maxEquipment; i++)
	{

	}

	return 0;
}
