#pragma once


//Displayeket és Printereket közös tömbben szeretnénk valahogy tárolni
class Display 
{
	unsigned serialNumber;
	unsigned price;
	unsigned age;
public:
	Display(unsigned serialNumber, unsigned price, unsigned age);

	void setAge(unsigned age);
	unsigned getAge() const;

	void print() const;
};
