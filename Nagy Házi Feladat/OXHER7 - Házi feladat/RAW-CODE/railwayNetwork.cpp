#include "railwayNetwork.h"

void RailwayNetwork::setStations(const string& stationTo, const string& stationFrom, const unsigned newData)
{
    table[stationTo][stationFrom] = newData;
}

void RailwayNetwork::initTable()
{
    for (unsigned i = 0; i < stationsNum; i++)          // vegigiteral a foatlon es 0 ba allitja az elemeit
        table[stations[i]][stations[i]] = 0;
}

void RailwayNetwork::addStation(const string& newData)
{
    string* temp = new string[stationsNum + 1];         // memoriat foglalunk eggyel tobb elemnek
    if (temp == nullptr) {
        cerr << "Memoriafoglalasi hiba" << endl;        // ha a memoria foglalas sikertelen hibakezeles
        exit(1);}

    for (unsigned i = 0; i < stationsNum; i++)          // masolas
        temp[i] = stations[i];
    temp[stationsNum] = newData;                        // uj adat hozzaadasa

    delete[] stations;                                  // a regi adatmezo torlese
    stations = temp;                                    // uj ertekkel beallitjuk
    stationsNum++;                                      // elemszamot noveljuk
}

void RailwayNetwork::loadTableFromCSV(const string& filename)
{
    ifstream file(filename);                        // megnyitjuk a filet
    string line, rowStation, cell;                  // line = sor amit olvasunk, rowStation = az elso oszlopa a filenak, cell = az adatmezo amiben vagyunk
    vector<string> allStation;                      // az osszes allomast tarolo stl tarolo

    if (!file.is_open()) {                          // hibakezele a file megnyitasban
        cerr << "CSV olvasasi hiba!" << endl;
        exit(1); }

    if (getline(file, line))                        //ez az allomasok neveinek beolvasasa
    {
        istringstream iss(line);
        getline(iss, cell, ',');                    // atugrojuk az ures mezot (0,0) a csv elejen
        while (getline(iss, cell, ','))             // ez csak az iss vegeig megy ami az elso sor
        {
            if(cell != "" || cell != "\0")          // az utolso mezore exception (az utolso mezo ,,)
            {
                allStation.push_back(cell);
                addStation(cell);
            }
        }
    }

    while (getline(file, line))                                 // a file vegeig megy
    {
        istringstream iss(line);
        getline(iss, rowStation, ',');                          // ezzel a sor elejen levo allomas nevet olvasom be a rowStation-ba
        for (unsigned i = 0; getline(iss, cell, ','); ++i)      // ez a sor vegeig megy (iss)
            if (i < allStation.size() && cell != "")            // ha a cell ures (sor vege) vagy nem lenne negyzetes a map
                table[allStation[i]][rowStation] = stoi(cell);  // beirjuk az adatot a cellabol a map-be
    }

    file.close();                                               //bezarjuk a filet
}

int RailwayNetwork::getWordLength() const       // osszeadja az osszes station nevenek a szohosszat
{
    int ans = 0;
    for (unsigned i = 0; i < stationsNum; i++)
        ans += stations[i].length();
    return ans;
}

