#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <traintime.h>

using namespace std;

class Train
{
private:
    string id;              //vonat azonosito
    string currentStation;  //az allomas amin a vonat eppen tartozkodik
    string* stations;       //az allomasok amin menetrend szerint mennie kellene
    int statNum;            //stations elemszama
    int speed;              //a vonat sebessege (az utazasi idohoz kell)

public:
    //konstruktorok
    Train() : id(""), currentStation(""), stations(nullptr), statNum(0), speed(0) {}
    Train(string id_, string currentStation_, int speed_, string* stations_, int statNum_);
    Train(const Train& other);
    ~Train() {delete[] stations;}

    //setterek
    void setId(string id_) {id = id_;}
    void setCurrentStation(string currentStation_) {currentStation = currentStation_;}
    void setSpeed(int speed_) {speed = speed_;}
    void setStations(string* stations_, int statNum_);

    //getterek
    string getId() const {return id;}
    string getCurrentStation() const {return currentStation;}
    int getSpeed() const {return speed;}
    string* getStations() const {return stations;}
    int getStatNum() const {return statNum;}

    //operatorok
    string& operator[](int index);

    //egyeb fuggvenyek
    void generateID();    //general egy random szamot es beallitja id-nek
    bool isAtStation(const string& station) const {return currentStation == station;}   //lekerdezi hogy az adott vonat a station allomason van-e
    friend istream& operator>>(istream& is, Train& train); //egy string streambol (a file olvasashoz) ir a tagvaltozokba
};

#endif // TRAIN_H
