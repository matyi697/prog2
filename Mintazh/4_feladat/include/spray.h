#ifndef SPRAY_H
#define SPRAY_H
#include <iostream>

class Spray
{
private:
    int type;
public:
    Spray() : type(0), used(false) {}
    Spray(int type_) : type(type_), used(false) {}
    void vaporize()
    {
        if (!used)
        {
            std::cout << "Permet: " << type << std::endl;
            used = true;
        }
        else
            std::cout << "Már felhasználták." << std::endl;
    }
    ~Spray() {}
    };

#endif // SPRAY_H
