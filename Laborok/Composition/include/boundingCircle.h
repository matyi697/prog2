#ifndef BOUNDINGCIRCLE_H
#define BOUNDINGCIRCLE_H
#include "rectangle.h"
#include "circle.h"
#include <cmath>
#include <iostream>

class boundingCircle
{
    public:
        boundingCircle(int a_) : innerSquare(a_), outerCircle((sqrt(2) * a_) / 2) {}
        boundingCircle() : innerSquare(1), outerCircle(sqrt(2)/ 2) {}
        double getArea () {return outerCircle.getArea() - innerSquare.getArea();}
        rectangle& getInnerSquare() {return innerSquare;} //ez lehet szar
        circle& getOuterCircle() {return outerCircle;}   //ez is lehet fos
        double getPerimeter() {return innerSquare.getPerimeter() + outerCircle.getCircumference();}
        void print();
    private:
        rectangle innerSquare;
        circle outerCircle;
};

#endif
