#ifndef RAILWAYNETWORK_H
#define RAILWAYNETWORK_H
#include <string>
#include <iostream>
#include "station.h"

using namespace std;

class RailwayNetwork
{
private:
    string* stations;   //az allomasok nevei, szigoruan sorrendben
    int statNum;        //a stations elemszama
    int** table;        //az allomasok egymastol valo tavolsaga km-ben megadva az oszlopok es sorok a stations sorrendjeben
    int tableNum;       //mivel negyzetes ezert ugyan annyi sor mint oszlop
public:
    //konstruktorok - destruktor
    RailwayNetwork() {}
    RailwayNetwork(const string* stations_, const int statNum_, const int tableNum_); //alapbol 0-k vannak a table-ben
    ~RailwayNetwork();

    //getterek
    string* getStations() const {return stations;}
    int getStationNumber() const {return statNum;}
    int getTableNumber() const{return tableNum;}
    int** getTable() const{return table;}

    //setterek
    void setStations(const string* stations_, const int statNum_);
    void setTable(const int** table_, const int tableNum_);

    //egyeb fugvenyek
    void loadTableFromCSV(const string& filename);  //a table 2D-s tombot egy csv filebol beolvassa
};

#endif // RAILWAYNETWORK_H
