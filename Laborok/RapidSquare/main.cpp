#include <iostream>
#include <cstring>

using namespace std;

inline int RapidSquare(int n) {return n*n;}

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++){
        int a = stoi(argv[i]);
        cout << RapidSquare(a) << " ";
    }
    return 0;
}
