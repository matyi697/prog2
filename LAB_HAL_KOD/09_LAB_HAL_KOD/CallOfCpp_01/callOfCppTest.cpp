#include <iostream>
#include "weapon.h"
#include "knife.h"
#include "pistol.h"
#include "railgun.h"

using namespace std;

int main() {
	
	Weapon excalibur(100);
	Knife knife;
	Pistol pistol;
	Railgun railgun;

	//Tárold a fenti fegyvereket közös tömbben (hetereogén kollekció)

	//Ezeket a kiírásokat cseréld le úgy, hogy for ciklussal történjen a heterogén kollekció felhasználásával!
	cout << excalibur.toString() << endl;
	cout << knife.toString() << endl;
	cout << pistol.toString() << endl;
	cout << railgun.toString() << endl;

	cout << endl;

	//Ezeket a kiírásokat cseréld le úgy, hogy for ciklussal történjen a heterogén kollekcióból!
	cout << "Damage caused with excalibur: " << excalibur.use() << endl;
	cout << "Damage caused with knife: " << knife.use() << endl;
	cout << "Damage caused with pistol: " << pistol.use() << endl;
	cout << "Damage caused with railgun: " << railgun.use() << endl;

	knife.sharpen();
	pistol.reload();
	railgun.recharge();


	cout << endl;

	//Ezeket a kiírásokat cseréld le úgy, hogy for ciklussal történjen a heterogén kollekcióból!
	cout << excalibur.toString() << endl;
	cout << knife.toString() << endl;
	cout << pistol.toString() << endl;
	cout << railgun.toString() << endl;

	return 0;
}
