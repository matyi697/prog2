#ifndef TRAINTIME_H
#define TRAINTIME_H


class TrainTime
{
private:
    int minute;
    int hour;
public:
    //konstruktorok
    TrainTime(const int h, const int m) : hour(h), minute(m) {}
    TrainTime() : hour(0), minute(0) {}
    //setterek, getterek
    void setTime(const int h, const int m);
    void setMinute(const int m);
    void setHour(const int h);
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

    bool operator<=(const TrainTime& other) const{return !(other < *this);}
    bool operator>=(const TrainTime& other) const{return !(*this < other);}

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
        if (m < 0)
        {
            h--;
            m += 60;
        }
        return TrainTime(h, m);
    }

    //egyeb fugvenyek
    void printTime();
};

#endif // TRAINTIME_H
