#include <iostream>
#include "head.h"

using namespace std;

//extern void printing_2(int N, char* str); ha nem header fileal oldjuk meg

void printing (int N, char* str) {
    for (int i = 0; i < N; i++)
        cout << str << endl;
}

int main()
{
    int N = 0;
    char szoveg[10];
    cin >> N >> szoveg;
    //printing(N, szoveg);
    printing_2(N, szoveg);
    return 0;
}
