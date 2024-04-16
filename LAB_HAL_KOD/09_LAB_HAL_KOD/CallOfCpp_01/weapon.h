#pragma once
#include <string>

class Weapon
{
protected:
	unsigned damage; // sebzés
public:
	Weapon(unsigned damage = 10);
	
	unsigned getDamage() const;
	void setDamage(unsigned damage);

	unsigned use(); // visszaadja a csökkentett sebzést
	
	std::string toString() const;
};