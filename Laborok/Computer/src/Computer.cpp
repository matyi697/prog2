#include "Computer.h"
#include <iostream>

// Statikus adattag inicializálása
unsigned Computer::nextId = 0;

Computer::Computer() : id(nextId++), clockSpeed(0) {}

// Másoló konstruktor implementációja
Computer::Computer(const Computer& other) : id(nextId++), clockSpeed(other.clockSpeed) {}

void Computer::print() const {
    std::cout << "Computer ID: " << id << ", Clock Speed: " << clockSpeed << std::endl;
}

void friendlyPrint(const Computer& comp) {
    std::cout << "Friend print - Computer ID: " << comp.id << ", Clock Speed: " << comp.clockSpeed << std::endl;
}
