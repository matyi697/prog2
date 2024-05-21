#include "train.h"

Train::Train(string id_, string currentStation_, int speed_, string* stations_, int statNum_)
{
    id = id_;
    currentStation = currentStation_;
    speed = speed_;
    statNum = statNum_;

    if (stations_ != nullptr && statNum > 0) {  // amennyiben nem ures a stations es a statNum
        stations = new string[statNum];         // memoria foglalas statNum darab stringre
        for (int i = 0; i < statNum; ++i)       // masolas
            stations[i] = stations_[i];
    } else
        stations = nullptr;                     // ha ures akkor nullptr
}

Train::Train(const Train& other)                // masolo konstruktor
{
    id = other.id;
    currentStation = other.currentStation;
    speed = other.speed;
    statNum = other.statNum;

    if (other.stations != nullptr) {            // ha nem ures az other
        stations = new string[statNum];         // memoria foglalas statNum darab stringre
        for (int i = 0; i < statNum; ++i)       // masolas
            stations[i] = other.stations[i];
    } else
        stations = nullptr;                     // ha ures akkor nullptr
}

Train::Train(const Train* other)
{
    id = other->id;
    currentStation = other->currentStation;
    statNum = other->statNum;
    speed = other->speed;

    if (other->stations != nullptr) {           // ha nem ures az other
        stations = new string[statNum];         // memoria foglalas statNum darab stringre
        for (int i = 0; i < statNum; ++i)       // masolas
            stations[i] = other->stations[i];
    } else
        stations = nullptr;                     // ha ures akkor nullptr
}

void Train::addStations(const string& newData) {
    string* temp = new string[statNum + 1];     //memoria foglalas statNum darab stringre

    if (temp == nullptr) {                      //hibakezels a memorias foglalasra
        cerr << "memoriafoglalasi hiba" << endl;
        exit(1); }

    for (int i = 0; i < statNum; i++)           //masolas
        temp[i] = stations[i];

    temp[statNum] = newData;

    delete[] stations;                          //regi felszabaditasa
    stations = temp;                            //uj dinamikus taggal egyenlove teszzuk
    statNum++;                                  //noveljuk elmszamot
}

string& Train::operator[](int index)
{
    if (index < 0 || index >= statNum) {
        cerr << "Allomas indexelesi hiba a Tain classban!" << endl;
        exit(1); }

    return stations[index];
}

void Train::generateID() {
    string temp;

    for (int i = 0; i < 5; i++)
        temp.push_back((rand() % 25) + 'A');    //veszunk egy random szamot A és Z kozott (25 karakter)

    setId(temp);                                //beallitjuk ID-t
}

void Train::printStations() const {
    for (int i = 0; i < statNum; i++)
        cout << stations[i] << " | ";
}
