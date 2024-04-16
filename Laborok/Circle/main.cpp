#include <iostream>
#include "src/circle.cpp"

using namespace std;

int main()
{
    cout << "Testing Circle..." << endl;
    circle c1;
    circle c2(10);

    c1.print();
    c2.print();

    cout << "A terulete: " << c1.getArea() << endl;
    cout << "A terulete: " << c2.getArea() << endl;
    cout << "A kerulete: " << c1.getCircumference() << endl;
    cout << "A kerulete: " << c2.getCircumference() << endl;

    c1.setR(c2.getR());
    c1.print();
    cout << "c1-nek a sugara:" << c1.getR() << endl;
    cout << "A c1-nek a terulete:" << c1.getArea() << endl;
    cout << "A c1-nek a kerulete:" << c1.getCircumference() << endl;
    return 0;
}
