#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <string>

using namespace std;

class TimeTable
{
private:
    string* stations; //az allomasok sorrendjeben
    int** times; //az idok az allomasok kozott
public:
    TimeTable();
};

#endif // TIMETABLE_H
