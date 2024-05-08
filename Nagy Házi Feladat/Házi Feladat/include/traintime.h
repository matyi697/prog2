#ifndef TRAINTIME_H
#define TRAINTIME_H

#include <iostream>

class TrainTime
{
private:
    int minute;
    int hour;
public:
    //konstruktorok
    TrainTime() : hour(0), minute(0) {}
    TrainTime(const int h, const int m) : hour(h), minute(m) {}

    //setterek, getterek
    void setTime(const int h, const int m) {hour = h; minute = m;}
    void setMinute(const int m) {minute = m;}
    void setHour(const int h) {hour = h;}
    int getHour() const {return hour;}
    int getMinute() const {return minute;}

    //osszehasonlito operatorok
    bool operator==(const TrainTime& other) const {return hour == other.hour && minute == other.minute;}

    bool operator<(const TrainTime& other) const {
        if (hour == other.hour)
            return minute < other.minute;
        return hour < other.hour;
    }

    bool operator>(const TrainTime& other) const {
        if (hour == other.hour)
            return minute > other.minute;
        return hour > other.hour;
    }

    //muveleti operatorok
    TrainTime operator+(const TrainTime& other) const {
        int h = hour + other.hour;
        int m = minute + other.minute;
        if (m >= 60)
        {
            h++;
            m -= 60;
        }
        return TrainTime(h, m);
    }

    TrainTime operator-(const TrainTime& other) const {
        int h = hour - other.hour;
        int m = minute - other.minute;
        if (m < 0) {
            h--;
            m += 60;
        }
        return TrainTime(h, m);
    }

    //egyeb fugvenyek
    void printTime() const {std::cout << hour << ":" << minute;};
};

#endif // TRAINTIME_H
