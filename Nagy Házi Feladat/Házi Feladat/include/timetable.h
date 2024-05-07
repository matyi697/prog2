#ifndef TIMETABLE_H
#define TIMETABLE_H

#include "railwayNetwork.h"
#include <string>

using namespace std;

class TimeTable
{
private:
    Train* trains;          //vonatok
    int trainNum;           //trains elemszama
    RailwayNetwork& railway;//a vasualozat amire a menetrendet szeretnenk
    TrainTime start;        //az elso vonat indulasi ideje
    TrainTime delta;        //ha a vonat a vegallomasra ert mennyi ido mulva fordul vissza
public:
    TimeTable(Train* trains_, int trainNum_, RailwayNetwork& railway_, TrainTime start_, TrainTime delta_);

    //getterek
    Train* getTrains() const { return trains; }
    int getTrainNum() const { return trainNum; }
    RailwayNetwork& getRailway() const { return railway; }
    TrainTime getStart() const { return start; }
    TrainTime getDelta() const { return delta; }

    //setterek
    void setTrains(Train* trains_, int trainNum_) {
        trains = trains_;
        trainNum = trainNum_;
    }
    void setRailway(RailwayNetwork& railway_) {railway = railway_;}
    void setStart(TrainTime start_) {start = start_;}
    void setDelta(TrainTime delta_) {delta = delta_;}

    //egyeb fuggvenyek
    void generateTimeTable() const;     //elmenti a "formazott" menetrendet egy csv file-ba
    void printTimeTable() const;        //kiirja a menetrendet
    void generateTableForTrain() const; //az adott vonatnak generalja le a menetrend sorat
};

#endif // TIMETABLE_H
