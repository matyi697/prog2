#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>

class rectangle
{
    public:
        rectangle(double a_, double b_) : a(a_), b(b_) {}
        rectangle(double a_) : a(a_), b(a_) {}
        rectangle() : a(0.0), b(0.0) {}
        double getA() {return a;}
        double getB() {return b;}
        void setA (double a_) {a = a_;}
        void setB (double b_) {b = b_;}
        double getArea() {return a*b;}
        double getPerimeter() {return 2*a + 2*b;}
        void print () {std::cout << "a=" << a << " " << "b=:" << b << std::endl;}
    private:
        double a;
        double b;
};

#endif // RECTANGLE_H
