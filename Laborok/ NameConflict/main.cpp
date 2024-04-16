#include <iostream>
namespace q {
    double a(double aa) {
        return 2 * aa;
}}

namespace w {
    double a(double aa) {
        return aa / 2;
}}

namespace e {
    double a(double aa) {
        return aa + 1;
}}

namespace r {
    double a(double aa) {
        return e::a(e::a(e::a(q::a(e::a(aa)))));
}}

int main()
{
    // az eredmény legyen 9
    std::cout << r::a(2);
    return 0;
}
