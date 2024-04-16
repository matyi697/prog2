#pragma once
#include <iostream>

class Malacpersely
{
	int osszeg;
public:
	Malacpersely(int penz=0) : osszeg(penz) {}
	void bedob(int penz);
	void atont(Malacpersely& masik);
	int ertek() const { return osszeg; }

};