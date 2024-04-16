// ha nem includeolnánk, nem ismerné a fordító a Person deklarációt
#include "person.h"

#include <iostream>
#include <cstring>



Person::Person() {
	printf("Default konstruktor lefut\n");
	name = nullptr;
	age = 0;	
}

// - ha mindkét paraméternek lenne default értéke, akkor nem kellene definiálni külön alapértelmezett konstruktort
Person::Person(const char* name, unsigned int age) {
	printf("Parameteres konstruktor lefut\n");
	this->name = nullptr;
	this->setName(name);
	this->age = age;
}
Person::Person(const Person& p)  {
	printf("Copy konstruktor lefut\n");
	this->name = nullptr;
	this->setName(p.getName());
	this->age = p.getAge();
}

// amit lefoglalsz, szabadítsd is fel!
Person::~Person() {
	printf("%s\tdestruktor lefut\n", name);
	// - ha nem adnánk értéket a this->name-nek (a null is értéknek számít), undefined behavior hibával kilépne a program
	// - bármilyen dinamikusan foglalt tömbről is van szó (függetlenül a tartalmától) delete[]-tel kell felszabadítani
	// - ha nem tömb, akkor delete
	delete[] this->name;
}

char* Person::getName() const {
	printf("%s\tgetName lefut\n", name);
	return name;
}

void Person::setName(const char* name) {
	printf("setName lefut\n");
	delete[] this->name;
	this->name = new char[strlen(name) + 1]; // +1 a null terminátornak
	strcpy(this->name, name);
}

unsigned int Person::getAge() const {
	printf("%s\tgetAge lefut\n", name);
	return this->age;
}

void Person::setAge(const unsigned int age) {
	printf("%s\tsetAge lefut\n", name);
	this->age = age;
}