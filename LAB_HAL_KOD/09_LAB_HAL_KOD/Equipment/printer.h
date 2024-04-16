#pragma once


//Displayeket és Printereket közös tömbben szeretnénk valahogy tárolni
class Printer
{
	unsigned serialNumber;
	unsigned price;
	unsigned cartridgePrice;
public:
	Printer(unsigned serialNumber = 0, unsigned price = 0, unsigned cartridgePrice = 0);

	void setCartridgePrice(unsigned cartridgePrice);
	unsigned getCartridgePrice() const;

	void print() const;
};
