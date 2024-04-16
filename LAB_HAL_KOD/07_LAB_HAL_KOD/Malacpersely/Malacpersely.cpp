#include "Malacpersely.h"

void Malacpersely::bedob(int penz) {
	osszeg += penz;
}

void Malacpersely::atont(Malacpersely& masik) {
	osszeg += masik.osszeg;
	masik.osszeg = 0;
}

