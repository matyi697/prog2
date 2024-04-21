#ifndef TRACTOR_H
#define TRACTOR_H
#include "spray.h"

class Tractor {
private:
    Spray** permetszer;
    int num;
public:
    Tractor() : permetszer(nullptr), num(0) {}
    ~Tractor () {delete [] permetszer;}
    void addSpray(Spray& newSpray){
        Spray** temp = new Spray*[num + 1];
        if (temp == NULL)
                return;
        for (int i = 0; i < num; i++)
            temp[i] = permetszer[i];
        temp[num] = &newSpray;
        delete [] permetszer; //lehet nem kell
        permetszer = temp;
        num++;
    }
    Spray operator[](int i){return *permetszer[i];}
};

#endif // TRACTOR_H
