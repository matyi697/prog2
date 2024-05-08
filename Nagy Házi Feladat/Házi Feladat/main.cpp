#include <iostream>
#include "train.h"
#include "railwayNetwork.h"
#include "timetable.h"
#include "traintime.h"

using namespace std;

int main(int argc, char* argv[])
{
    RailwayNetwork r1;
    r1.loadTableFromCSV(argv[1]);   //testelve
    r1.addStation("tonyas");

    for(int i = 0; i < r1.getStationsNum(); i++)
        cout << r1.getStation(i) << " ";


    return 0;
}
