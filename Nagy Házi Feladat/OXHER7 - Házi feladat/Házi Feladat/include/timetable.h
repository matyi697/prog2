#ifndef TIMETABLE_H
#define TIMETABLE_H

#include "railwayNetwork.h"
#include "traintime.h"
#include "memtrace.h"
#include <string>
#include <fstream>

using namespace std;

class TimeTable
{
private:
    Train** trains;          // vonatok
    int trainNum;            // trains elemszáma
    RailwayNetwork& railway; // a vasúthálózat, amire a menetrendet szeretnénk megnezni
    TrainTime start;         // az első vonat indulási ideje

public:
    //Konstruktorok & Destruktorok
    TimeTable() : trains(nullptr), trainNum(0), railway(*(new RailwayNetwork())), start() {}
    TimeTable(RailwayNetwork& railway_)
                : trains(nullptr), trainNum(0), railway(railway_), start(TrainTime()) {}
    TimeTable(Train** trains, int trainNum, RailwayNetwork& railway, TrainTime start)
                : trains(trains), trainNum(trainNum), railway(railway), start(start) {}
    ~TimeTable();

    // Getterek
    Train** getTrains() const { return trains; }            // a vonatok dinamikus tagjaval ter vissza
    int getTrainNum() const { return trainNum; }            // a vonatok elemszamaval ter vissza
    RailwayNetwork& getRailway() const { return railway; }  // a railway referenciajaval ter vissza
    TrainTime getStart() const { return start; }            // az indulsi idovel ter vissza
    Train* getTrain (const string& id) const;               // egy aditt vonatot keres ki a vonatok tombjbol id alapjan

    // Setterek
    void setTrains(Train** trains_, int trainNum_);                     // a dinamikus tagot ezzel lehet bealltanigy meglevo Trains**-ra
    void setStart(TrainTime start_) { start = start_; }

    // Egyéb függvények
    void addTrain(const Train* train);                  // hozzafuz egy vonatot a Trains**-hoz
    void loadTrainsFromFile(const string& filename);    // a trains-t egy csv filebol tolti be
    void saveTimeTable(const string& filename) const;   // elmenti egy csv fileba a menetrendet
    void printTimeTable() const;                        // kiirja a standard outputra a menetrendet
};

#endif // TIMETABLE_H
