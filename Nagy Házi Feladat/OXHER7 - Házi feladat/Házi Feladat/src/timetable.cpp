#include "timetable.h"

TimeTable::~TimeTable()
{
    for (int i = 0; i < trainNum; ++i)      //felszabadirjuk a trains minden elemet egyesevel
        delete trains[i];
    delete[] trains;
}

Train* TimeTable::getTrain(const string& id) const
{
    for (int i = 0; i < trainNum; i++)
        if (trains[i]->getId() == id)
            return trains[i];
    return nullptr;
}

void TimeTable::setTrains(Train** trains_, int trainNum_)
{
    if (trains != nullptr)
        delete[] trains;
    trains = trains_;
    trainNum = trainNum_;
}

void TimeTable::addTrain(const Train* train)
{
    Train** newTrains = new Train*[trainNum + 1];       // helyet foglalunk trainNum + 1 elemnek
    for (int i = 0; i < trainNum; i++)                  // masolas
        newTrains[i] = trains[i];

    newTrains[trainNum] = new Train(*train);            // az uj elem letrehozasa
    delete[] trains;                                    // felszabaditjuk a memoriat
    trains = newTrains;                                 // uj ertek megadasa
    trainNum++;
}

void TimeTable::loadTrainsFromFile(const string& filename)
{
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "A file megnyitasa nem sikerult! " << filename << endl;
        exit(-1);}

    string line;                    // ebben tarolom a sort
    vector<string> data;            // ebben tarolom a sor adatmezoket vektorosan


    while (getline(file, line))     // a file vegeig megy
    {
        if (line.empty())           // ures sorok ugrasa (utolso sor)
            continue;

        stringstream ss(line);      // stringstream a sorra
        string item;                // a cella adat

        while (getline(ss, item, ','))
        {
            if (item != "" || item != "\0")     // ha nem ures cella (a sor vege ,,)
                data.push_back(item);           // bepusholjuk az adatokat a data-ba
        }

        string id = data[0];                            // az uj train id
        int speed = stoi(data[1]);                      // az uj train sebessege
        int numStations = data.size() - 2;              // az id es speed miatt - 2
        string* stations = new string[numStations];     // az vonat allomasainak tombje
        for (int i = 0; i < numStations; ++i)           // feltoltjuk az allomasokat
            stations[i] = data[i + 2];                  // a + 2 szinten a speed es id ugrasa

        Train* newTrain = new Train(id, stations[0], speed, stations, numStations);     // ez az uj train elem
        Train** temp = new Train*[trainNum + 1];                                        // ezaz uj train tomb, amihez hozza fuzom az elozo sort

        for (int i = 0; i < trainNum; ++i)              // masolas
            temp[i] = trains[i];

        temp[trainNum] = newTrain;                      // uj elem hozzaadasa
        delete[] trains;                                // regi torlese
        trains = temp;                                  // uj train tomb bealitasa
        trainNum++;                                     // elemszam novelese

        data.clear();                                   // a data-t minden sor vegen torolni kell
        delete [] stations;                             // a stations segedvaltozo feszabaditasa
    }

    file.close();
}

void TimeTable::saveTimeTable(const string& filename) const
{
    ofstream outFile(filename);

    if (!outFile.is_open()){                        // hibakezeles
        cerr << "File iras hiba" << endl;
        exit(-1);}

    outFile << "Vonat ID, Jelenlegi állomás, ";                 // header mezok kiirasa
    for (unsigned i = 0; i < railway.getStationsNum() - 1; ++i) // a current station a -1
        outFile << "Allomas " << i+1 << "," << " ,";
    outFile << "\n";

    for (int i = 0; i < trainNum; ++i)                          // ezzel a vonatokon iteralunk vegig
    {
        Train* train = trains[i];
        outFile << train->getId() << "," << train->getCurrentStation() << ",";      // beirjuk a fileba az allomast ahhol vagyunk epp

        TrainTime currentTime = start;
        string* stations = train->getStations();

        for (int j = 0; j < train->getStatNum(); ++j)                               // az allomasokon iteralunk vegig
        {
            int distance = railway.getTableCell(train->getCurrentStation(), stations[j]);       // kizamolja a tavolsagot a jelenlegi es kovetkezo allomas kozott
            currentTime.hourToTime(train->calculateTime(distance));                           // kiszamolja a menetidot a ket allomas kozott

            outFile << stations[j] << ", " << (currentTime.getHour() < 10 ? "0" : "") << currentTime.getHour()  // a ket szamjegyes kiiras
                    << ":" << (currentTime.getMinute() < 10 ? "0" : "") << currentTime.getMinute();

            if (j < trains[i]->getStatNum() - 1)
                outFile << ", ";
        }
        delete [] stations;
        outFile << "\n";
    }
    cout << "A file írás sikeres! (" << filename << ")" << endl;
    outFile.close();
}

void printHeaderTable()     // a menetrend ascii artot csinalja
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif

    ifstream text("header.txt");
    string line;

    if (!text.is_open())
        cerr << "File olvasasi hiba";

    while (getline(text, line))
        cout << line << endl;
    cout << endl << endl;
    text.close();
}

void TimeTable::printTimeTable() const
{
    printHeaderTable();

    int maxrow = 7 + railway.getWordLength() + railway.getStationsNum() * 11;

    for (int i = 0; i < maxrow; i++)
        cout << "_";

    cout << endl;
    cout << "| id  | Jelenlegi állomás | Érkezések: |";
    cout << endl;

    for (int i = 0; i < maxrow; i++)
        cout << "\u203E";               // ez egy felso vonas unicode character, a windows cmd nem szokta szeretni az unicode karaktereket

    cout << endl;

    for (int i = 0; i < trainNum; ++i)
    {
        Train* train = trains[i];
        cout << "|" << train->getId() << "| " << train->getCurrentStation();    // kiirjuk az allomasokat

        for (unsigned i = 0; i < 18 - train->getCurrentStation().length(); i++)
            cout << " ";

        cout << "|";

        TrainTime currentTime = start;
        string* stations = train->getStations();

        for (int j = 0; j < train->getStatNum(); ++j)
        {
            int distance = railway.getTableCell(train->getCurrentStation(), stations[j]);   // a jelenlegi allomastol a kovetkezoig valo tavolsag

            TrainTime temp;
            temp.hourToTime(train->calculateTime(distance));
            currentTime = currentTime + temp;                       //az elozo idohoz adjuk hozza az uj menetidot

            if (j != 0)                                             //ido kiiras
            {
                cout << stations[j] << ": ";
                currentTime.printTime();
                cout << "    ";
            }
            train->setCurrentStation(stations[j]);                  //a vonat leptetese
        }
        cout << endl;
    }
    cout << endl << endl;
}



