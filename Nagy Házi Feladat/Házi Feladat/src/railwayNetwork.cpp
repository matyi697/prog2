#include "railwayNetwork.h"
/*
void RailwayNetwork::setStations(string* stations_, int statNum_)
{
    delete[] stations;
    statNum = statNum_;
    stations = new string[statNum_];
    for (int i = 0; i < statNum_; ++i)
    {
        stations[i] = stations_[i];
    }
}

void RailwayNetwork::setTimes(int** _times, int _timesNum)
{
    for (int i = 0; i < statNum; ++i)
    {
        delete[] times[i];
    }
    delete[] times;

    timesNum = _timesNum;
    times = new int*[_timesNum];
    for (int i = 0; i < _timesNum; ++i)
    {
        times[i] = new int[_timesNum];
        for (int j = 0; j < _timesNum; ++j)
        {
            times[i][j] = _times[i][j];
        }
    }
}

void RailwayNetwork::loadTimesFromCSV(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    int row = 0;
    while (getline(file, line))
    {
        stringstream ss(line);
        string cell;
        int col = 0;
        while (getline(ss, cell, ','))
        {
            times[row][col] = stoi(cell);
            col++;
        }
        row++;
    }

    file.close();
}
*/
