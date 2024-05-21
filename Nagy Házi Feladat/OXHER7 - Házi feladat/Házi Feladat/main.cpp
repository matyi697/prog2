#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "train.h"
#include "railwayNetwork.h"
#include "traintime.h"
#include "timetable.h"
#include "memtrace.h"

using namespace std;

void printHeader()  // a menetrend ascii art kiirasa
{
    ifstream text("header.txt");
    string line;

    if (!text.is_open())
        cerr << "File olvasasi hiba";

    while (getline(text, line))
        cout << line << endl;
    cout << endl << endl;
    text.close();
}

int main(int argc, char* argv[])
{
    if (argc < 3) { //ha az argumentumvektoron nincs eleg adat
    cerr << "A helyes hasznalat: " << argv[0] << " allomasok.csv vonatok.csv" << endl;
    exit(-1);}

    RailwayNetwork r1;
    r1.loadTableFromCSV(argv[1]);       // betoltjuk az adatokat a filebol (allomasok.csv)

    TimeTable t1(r1);                   // hozzadjuk az r1-et a t1-hez
    t1.loadTrainsFromFile(argv[2]);     // betoltjuk az adatokat a filebol (vonatok.csv)

    while (1)
    {
        printHeader();
        int menu = 0;   // a user input hogy melyik menut valasztotta

        cout << "Mit szeretnél csinálni?"           << endl
             << "\t 1: kiíratás a terminálba"       << endl
             << "\t 2: kiíratás fileba"             << endl
             << "\t 3: vonat menetidő lekérdezés"   << endl
             << "\t 0: kilépés"                     << endl;

        cin >> menu;

        switch (menu)   // a user input feldolgozasa
        {

        case 1:     // menetrend kiitasa a terminalba
        {
            t1.printTimeTable();
            cout << "Nyomj entert a folytatáshoz !" << endl;
            cin.ignore();
            cin.get();
        }
        break;

        case 2:     // menetrend fileba irasa
        {
            cout << "Írd be a file nevét: ";
            string filename;
            cin >> filename;
            filename += ".csv";                 //hozzafuzi a filenevhez a .csv kiterjesztest
            t1.saveTimeTable(filename);
            cout << endl << "Nyomj entert a folytatáshoz !" << endl;
            cin.ignore();
            cin.get();
        }
        break;

        case 3:     //ket allomas kozotti menetido lekerdezese
        {
            cout << "Add meg a két allomás nevét: [allomas1] [allomas2]" << endl;
            string station1, station2;
            cin >> station1 >> station2;
            int distance = r1.getTableCell(station1, station2);     //ez a tavolsag a ket hely kozott

            if (distance <= 0) {
                cerr << "Az állomások amiket megadtál nem léteznek";
                exit(-1);}

            cout << "Add meg a vonat azonosítót:" << endl;
            string id;
            cin >> id;
            Train* userTrain = t1.getTrain(id); // kikeresi a vonatot id alapjan
            if (userTrain == nullptr) {         // nem talalt vonatot ilyen id alapjan
                cerr << "Nem letezo vonatot adtal meg!";
                exit(-1); }

            int speed = userTrain->getSpeed();
            TrainTime userTime;
            userTime.hourToTime((double)distance / (double)speed);      // kiszamolja az idot (t = s / v)
            cout << "A(z) " << id << " azonosítóval rendelkező vonat ";
            userTime.printTime();
            cout << " idő alatt teszi meg a távot." << endl;
            cout << "Nyomj entert a folytatáshoz !" << endl;
            cin.ignore();
            cin.get();
        }
        break;

        case 0:
            return 0;
            break;
        }

    //a kepernyo torles command nem cross platform kompatibilis szoval makrokkal oldottam meg
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
    }

    return 0;
}
