#ifndef TRAIN_H
#define TRAIN_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "memtrace.h"

using namespace std;

class Train
{
private:
    string id;              // vonat azonosito
    string currentStation;  // az allomas amin a vonat eppen tartozkodik
    string* stations;       // az allomasok amin menetrend szerint mennie kellene (nem minden allomast tartalmaz)
    int statNum;            // stations elemszama
    int speed;              // a vonat sebessege km/h -ban (az utazasi idohoz kell)

public:
    // Konstruktorok & Destruktorok
    Train() : id(""), currentStation(""), stations(nullptr), statNum(0), speed(0) {}
    Train(string id_, string currentStation_, int speed_, string* stations_, int statNum_);
    Train(const Train& other);
    Train(const Train* other);
    ~Train() { delete[] stations; }

    //Setterek
    void setId(string id_) { id = id_; }                                                // az ID-t alitja be
    void setCurrentStation(string currentStation_) {currentStation = currentStation_;}  // a jelenlegi allomast allitja be
    void setSpeed(int speed_) { speed = speed_; }                                       // a vonat sebesseget allitja be
    void addStations(const string& newData);                                            // hozzafuz allomasokat a stationshoz

    //Getterek
    string getId() const { return id; }                         // az Id-val ter vissza
    string getCurrentStation() const { return currentStation; } // a jelenlegi allomas nevevel ter vissza
    int getSpeed() const { return speed; }                      // a vonat sebessegevel ter vissza
    string* getStations() const { return stations; }            // az allomasok dinamikus tagjaval ter vissza
    int getStatNum() const { return statNum; }                  // az allomasok szamaval ter vissza

    //Operatorok
    string& operator[](int index);  // a stations-nak az egyszerubb lekerdezesere

    // egyeb fuggvenyek
    void generateID();                                                                      // general egy random szamot es beallitja id-nek
    bool isAtStation(const string& station) const { return currentStation == station; }     // lekerdezi hogy az adott vonat a <station> allomason van-e
    double calculateTime(int distance) const { return (double)distance / (double)speed; }   // kiszamolja a menetidot egy tavolsag adatbol
    void printTrain() const { cout << id << " | " << speed << " | "; }                      // a vonat alapveto adatat irja ki (debuggingra kellett)
    void printStations() const;
};

#endif // TRAIN_H
