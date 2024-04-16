#include <iostream>
#include "src/boundingCircle.cpp"

using namespace std;

int main()
{
    cout << "testing Bounding Cicle..." << endl;
    boundingCircle b1;
    boundingCircle b2(10);

    b1.print();
    b2.print();

    cout << "A c1 terulet: " << b1.getArea() << endl;
    cout << "A c2 terulet: " << b2.getArea() << endl;
    cout << "A c1 kerulet: " << b1.getPerimeter() << endl;
    cout << "A c2 kerulet: " << b2.getPerimeter() << endl;

    b1.getInnerSquare().print();
    b1.getOuterCircle().print();
    return 0;
}
