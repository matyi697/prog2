#ifndef TRAINTIME_H
#define TRAINTIME_H

#include <iostream>
#include <cmath>
#include <string>
#include "memtrace.h"

class TrainTime
{
private:
    int minute;
    int hour;

public:
    //Konstruktorok
    TrainTime() {hour = 0; minute = 0;}
    TrainTime(const int h, const int m) {hour = h; minute = m;}

    //Setterek
    void setTime(const int h, const int m) { hour = h; minute = m; }    // beallitja az ido ora es perc tagjat
    void setMinute(const int m) { minute = m; }                         // beallitja az ido perc tagjat
    void setHour(const int h) { hour = h; }                             // beallitja az id ora tagjat

    //Getterek
    int getHour() const { return hour; }        // visszater az ora taggal
    int getMinute() const { return minute; }    // visszater a perc taggal

    //Osszehasonlito operatorok
    bool operator==(const TrainTime& other) const { return hour == other.hour && minute == other.minute; }  // ket idot hasonlit ossze egyenlosegre

    bool operator<(const TrainTime& other) const {  // ket idot hasonlit ossze relaciora
        if (hour == other.hour)
            return minute < other.minute;
        return hour < other.hour;
    }

    bool operator>(const TrainTime& other) const { // ket idot hasonlit ossze relaciora
        if (hour == other.hour)
            return minute > other.minute;
        return hour > other.hour;
    }

    //Muveleti operatorok
    TrainTime& operator=(const TrainTime& other) {
    if (this != &other) {
        hour = other.hour;
        minute = other.minute;
    }
    return *this;
}

    TrainTime operator+(const TrainTime& other) const {     // ket idot ad ossze
        int h = hour + other.hour;
        int m = minute + other.minute;
        if (m >= 60)
        {
            h++;
            m -= 60;
        }
        return TrainTime(h, m);
    }

    TrainTime operator-(const TrainTime& other) const {     // ket idot von ki egymasbol
        int h = hour - other.hour;
        int m = minute - other.minute;
        if (m < 0) {
            h--;
            m += 60;
        }
        return TrainTime(h, m);
    }

    //egyeb fugvenyek
    void hourToTime(const double hours) {       // orabol kiszamolja az egesz perceket es orakat
        int h = floor(hours);
        int m = floor((hours - h) * 60);

        setTime(h, m);
    }

    void minToTime(const int mins) {            // orabol kiszamolja az egesz perceket es orakat
        minute += mins;
        hour += minute / 60;
        minute %= 60;
        hour %= 24;
    }

    void printTime() const {                    // kiirja az idot ket szamjegyen, vezeto 0-val
        std::cout.fill('0');
        std::cout.width(2);
        std::cout << hour << ":";
        std::cout.width(2);
        std::cout << minute;
    }
};

#endif // TRAINTIME_H
