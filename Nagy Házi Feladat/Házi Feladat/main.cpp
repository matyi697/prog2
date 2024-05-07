#include <iostream>
#include "train.h"
#include "railwayNetwork.h"
#include "timetable.h"
#include "traintime.h"

using namespace std;

int main(int argc, char* argv[])
{
    string stations[] = {"Budapest", "Pécs", "Szeged"};
    int statNum = sizeof(stations) / sizeof(stations[0]);
    int tableNum = statNum;
    RailwayNetwork network(stations, statNum, tableNum);

    TrainTime start(8, 0);  //8:00
    TrainTime delta(0, 20); //20 perc a delta
    Train train1("123", "Budapest", 100, stations, statNum);
    Train train2("456", "Pécs", 120, stations, statNum);
    Train* trains = new Train[2];
    trains[0] = train1;
    trains[1] = train2;
    int trainNum = 2;
    TimeTable timetable(trains, trainNum, network, start, delta);

    timetable.printTimeTable();

    timetable.generateTimeTable();

    //timetable.printTimeTable();

    delete[] trains;
    return 0;
}
