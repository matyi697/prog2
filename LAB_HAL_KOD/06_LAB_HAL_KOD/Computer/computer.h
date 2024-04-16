#pragma once
#include <stdio.h>

class Computer
{
	unsigned nextId;
	unsigned id;
	unsigned clockSpeed;
public:
	Computer();
	Computer(const Computer&);
	unsigned getClockSpeed() const;
	void print() const;
	friend void friendlyPrint(const Computer&);
};

void friendlyPrint(Computer&);
