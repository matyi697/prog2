#ifndef RAILWAYNETWORK_H
#define RAILWAYNETWORK_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include "station.h"

using namespace std;

class RailwayNetwork
{
private:
    string* stations;
    unsigned stationsNum;
    map<string, map<string, int>> table;
public:
    RailwayNetwork(): stations(nullptr), stationsNum(0) {}
    ~RailwayNetwork() {delete [] stations;}
    //getterek
    map<string, map<string, int>> getTable() const {return table;}
    string& getStation(const unsigned index) const {return stations[index];}
    unsigned getStationsNum () const {return stationsNum;}

    //setterek
    void addStation(const string& newData);
    void setStations(const string& stationFrom, const string& stationTo, const unsigned newData);
    void initTable();

    //egyeb fugvenyek
    void loadTableFromCSV(const string& filename);  //a table 2D-s tombot egy csv filebol beolvassa
};

#endif // RAILWAYNETWORK_H
