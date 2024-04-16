#include <iostream>
#include "src/rectangle.cpp"

using namespace std;

int main()
{
    cout << "Testing Rectagle..." << endl;
    rectangle r1;
    rectangle r2(4);
    rectangle r3(2, 5);

    r1.print();
    r2.print();
    r3.print();

    cout << r1.getArea() << endl;
    cout << r2.getArea() << endl;
    cout << r3.getArea() << endl;

    cout << r1.getPerimeter() << endl;
    cout << r2.getPerimeter() << endl;
    cout << r3.getPerimeter() << endl;

    r3.setA(r2.getA());
    r3.setB(r2.getB());
    r3.print();
    cout << "A terulete az r3-nak: " << r3.getArea() << endl;
    cout << "a kerulete az r3-nak: " << r3.getPerimeter() << endl;
    return 0;
}
