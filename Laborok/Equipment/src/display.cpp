#include <iostream>
#include "display.h"

using namespace std;

//A serialNo és a price paramétereket is el kell tárolnunk valahol
Display::Display(unsigned serialNumber, unsigned price, unsigned age): age(age) {}

void Display::setAge(unsigned age)
{
	this->age = age;
}

unsigned Display::getAge() const
{
	return age;
}

void Display::print() const {

	cout << " Age (Display): " << age;
}
