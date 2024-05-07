 #include <fstream> 
#include "person.h"
#include "comparable.h" 
#include "serializable.h" 
#include "saver.h" 

using namespace std;

int main()
{
	const unsigned PEOPLE_COUNT = 4;

	//Vele fogunk összehasonlítani az 1.b-ben
	Person* pisti = new Person(30, 180, 85);
	Person* people[PEOPLE_COUNT];

	people[0] = new Person(40, 182, 90);
	people[1] = new Person(12, 100, 50);
	people[2] = new Person(30, 180, 85);
	people[3] = new Person(40, 182, 90);

	//1.a feladat tesztelése
	cout << "\tSerializing people" << endl;
	cout << "State\tIndex\tAge\tHeight\tWeight" << endl;
	for (unsigned i = 0; i < PEOPLE_COUNT; i++)
	{
		cout << "Ser.\t" << i << '\t' << *people[i] << endl;
	}

	//1.b feladat tesztelése
	//cout << "\tComparing people in array with 'pisti'" << endl;
	//cout << "State\tIndex\tAge\tHeight\tWeight" << endl;
	//for (unsigned i = 0; i < PEOPLE_COUNT; i++)
	//{
	//	cout << "------------------------------------" << endl; 
	//	cout << "Comp.\t" << i << '\t' << *people[i] << endl;
	//	cout << "Has the same age as Pisti? "  << (*people[i] == *pisti) << endl;
	//	cout << "Is younger than Pisti? " << (*people[i] < *pisti) << endl;
	//}

	//2.a feladat: írd ki a people tömb elemeit a "people.txt" fájlba
	//
	//
	//
	//

	delete pisti;
	for (unsigned k = 0; k < PEOPLE_COUNT; k++)
		delete people[k];

	getchar();
	return 0;
}