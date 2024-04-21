#include <iostream>
#include "src/car.cpp"

using namespace std;

int main()
{
    Car c1(107);
    Car c2(999);
    Car c3(2000);
    c1.entersTrack();
    c3.entersTrack(); //a 2000-s azonosítójú autó másodikként lép pályára
    c2.entersTrack();
    cout << c3; //(*) Kiirjuk c3 adatait: "Car #2000 entered the track as the 2. car"
    if (c3 < c2) //(**) Ha c3 előbb került pályára, mint c2
    {
        cout << c3.getNumber() << " entered the track earlier.";
    }
}
