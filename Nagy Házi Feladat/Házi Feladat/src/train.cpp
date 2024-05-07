#include "train.h"
#include<iostream>

using namespace std;

Train::Train(string id_, string currentStation_, int speed_, string* stations_, int statNum_)
{

}

Train::Train(const Train& other)
{

}

void Train::setStations(string* stations_, int statNum_)
{
    //delete[] stations;
    stations = nullptr;
    statNum = statNum_;
    if (statNum > 0){
        stations = new string[statNum];
        for (int i = 0; i < statNum; ++i)
            stations[i] = stations_[i];
    }
    else
        stations = nullptr;
}

void Train::generateID()
{

}
string& Train::operator[](int index)
{
    if (index < 0 || index >= statNum) {
        cerr << "Allomas indexelesi hiba a Tain classban!" << endl;
        exit(1);
    }
    return stations[index];
}
