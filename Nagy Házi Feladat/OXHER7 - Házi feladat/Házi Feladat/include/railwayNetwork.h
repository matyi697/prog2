#ifndef RAILWAYNETWORK_H
#define RAILWAYNETWORK_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include "station.h"
#include "memtrace.h"

using namespace std;

class RailwayNetwork
{
private:
    string* stations;                       // az allomasok nevei dinamikusan kezelve
    unsigned stationsNum;                   // az allomasok szama
    map<string, map<string, int>> table;    // ebben a 2D map-ben tarolom az allomasok egymastol valo tavolsagat km-ben

public:
    //Konstruktorok & Destruktorok
    RailwayNetwork(): stations(nullptr), stationsNum(0) {}
    ~RailwayNetwork() { delete [] stations; }

    //Getterek
    map<string, map<string, int>> getTable() const { return table; }                    // az egesz mapet adja visza
    string& getStation(const unsigned index) const { return stations[index]; }          // az n.-ik allomas nevet adja vissza
    unsigned getStationsNum () const { return stationsNum; }                            // az allomasok szamaval ter vissza
    int getTableCell(const string& from, const string& to) { return table[from][to]; }  // ket allomas kozotti tavolsaggal ter vissza, ha nem letezik akkor 0

    //Setterek
    void setStations(const string& stationFrom, const string& stationTo, const unsigned newData);   // csak debuggingra hasznaltam
    void initTable();                                                                               // inicializalja a mapet (a foatlot 0 val tolti ki)

    //Egyeb fugvenyek
    void addStation(const string& newData);         // debuggingra volt csak hasznalva
    void loadTableFromCSV(const string& filename);  // a table 2D-s tombot egy csv filebol beolvassa
    int getWordLength() const;                      // osszeadja az allomasok szohosszat, a kiiratashoz kell
};

#endif // RAILWAYNETWORK_H
