#include "railwayNetwork.h"

void RailwayNetwork::setStations(const string& stationTo, const string& stationFrom, const unsigned newData)
{
    table[stationTo][stationFrom] = newData;
}

void RailwayNetwork::initTable()
{
    for (int i = 0; i < stationsNum; i++)   //azonos nevu allomasok egymastol valo tavolsaga 0
        table[stations[i]][stations[i]] = 0;
    //map tukrozes
}

void RailwayNetwork::addStation(const string& newData)
{
    string* temp = new string[stationsNum + 1];
    if (temp == nullptr)
    {
        cerr << "memoriafoglalasi hiba" << endl;
        return;
    }
    for (int i = 0; i < stationsNum; i++)
        temp[i] = stations[i];
    temp[stationsNum] = newData;

    delete[] stations;
    stations = temp;
    stationsNum++;
}

void RailwayNetwork::loadTableFromCSV(const string& filename)
{
    ifstream file(filename);
    string line, rowStation, cell; // a sor elejen levo allomas neve a map hasheleshez kell
    vector<std::string> allStation;

    if (!file.is_open())
    {
        cerr << "szar a csv file" << endl;
        return;
    }

    if (getline(file, line))    //ez az allomasok neveinek beolvasasa
    {
        istringstream iss(line);
        getline(iss, cell, ',');    //atugrojuk az ures mezot (0,0)
        while (getline(iss, cell, ','))      //ez csak az iss vegeig megy ami az elso sor
        {
            allStation.push_back(cell);
            addStation(cell);
        }
    }

    while (getline(file, line))     //a file vegeig megy
    {
        istringstream iss(line);
        getline(iss, rowStation, ',');  //ezzel a sor elejen levo allomas nevet olvasom be
        for (unsigned i = 0; getline(iss, cell, ','); ++i)      //ez a sor vegeig megy (iss)
            if (i < allStation.size() && cell != "")            //ha a cell ures (sor vege) vagy nem lenne negyzetes a map
                table[allStation[i]][rowStation] = stoi(cell);
    }

    file.close();
}
