#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include <iostream>

class circle
{
    public:
        circle() : r(0.0) {}
        circle(double r_) : r(r_) {}
        double getArea() {return (r*r) * M_PI;}
        double getCircumference() {return 2 * r * M_PI;}
        double getR() {return r;}
        void print() {std::cout << "R:" << r << std::endl;}
        void setR(double r_) {r = r_;}
    private:
        double r;
};

#endif
