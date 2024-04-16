#include "boundingCircle.h"
#include <iostream>

void boundingCircle::print()
{
     std::cout << "Inner sqare: a=" << innerSquare.getA() << " b=" << innerSquare.getB() << "  Outer Circle: r=" << outerCircle.getR() << std::endl;
}
