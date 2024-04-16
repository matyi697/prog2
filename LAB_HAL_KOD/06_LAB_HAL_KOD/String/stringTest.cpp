#include <iostream>
#include "string.h"

using namespace std;
using namespace HomeMadeString;

int main()
{
	// Teszteljük a paraméter nélküli konstruktort
	String s1;
	// Teszteljük a régi típusú sztringet váró konstruktort
	String s2 = "Hello, hello!";

	// Kiíratjuk az eredményeket:
	cout << "s1";
	s1.print(cout);
	cout << endl;

	cout << "s2\t\t";
	s2.print(cout);
	cout << endl << endl;

	// Teszteljük a másoló függvényt, kiíratjuk
	String::copy(s1, s2);
	cout << "s1:=s2\t\t";
	s1.print(cout);
	cout << endl;
	cout << "s2\t\t";
	s2.print(cout);
	cout << endl;

	// Teszteljük az összehasonlító függvényt
	if (String::compare(s1, s2))
		cout << "s1 and s2 are the same!" << endl;

	// Teszteljük a "minta" konstruktort
	String s3('-', 15);
	cout << "s3\t\t";
	s3.print(cout);
	cout << endl;

	// Teszteljük a concatenate függvényt és a másoló konstruktort
	String s4 = String::concatenate(s2, s3);
	cout << "s4:=s2+s3\t";
	s4.print(cout);
	cout << endl;

	// Teszteljük az at függvényt
	cout << "s4.at(*)\t";
	for (int i = 0; i<s4.getLength(); i++)
		cout << s4.at(i);
	cout << endl;

	// C Stringet visszaadó függvény tesztje
	cout << "s4 cstr\t\t";
	cout << s4.getCString() << endl;

	return 0;
}

