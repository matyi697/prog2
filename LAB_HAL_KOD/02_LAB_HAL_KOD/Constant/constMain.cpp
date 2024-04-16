#include <stdio.h>

int main()
{
	// 1.
	// const int i; // nem OK: konstans változót mindig inicializálni kell

	// 2.
	const int i = 90; // Az i értéke nem változtatható közvetlenül
	// i++; // Tehát ne változtassuk

	// 3.
	const int j = 90;
	// int *p = &i; // Már itt konverziós hiba, a fordító figyel...
	const int *p = &j; // így a helyes
	// (*p)++; // az érték konstans, így nem változtatható meg

	// 4.
	const int v1[] = { 1,2,3 }; // Tömb is lehet konstans
	// v1[1]++; // az érték konstans, így nem változtatható meg

	// 5.
	const int k = 255;
	int v2[k]; // OK. Ugyanaz, mint int v2[255]. Konstanst felhasználhatunk deklarációban, mert fordítási időben már kiértékelődik.

	// A pointereknél más a helyzet. Lehet a pointer konstans, vagy a mutatott érték.
	// int* const egy konstans pointer egy nem konstans int értékre
	// int const* egy nem konstans pointer egy konstans intre
	// const int* const egy konstans pointer egy konstans intre
	// Tehát: ami a csillag után van, az a pointerre vonatkozik, ami előtte az pedig a mutatott értékre :)

	// 6.
	char s1[] = "Hello VIK World!";
	const char *pc = s1; // Ez melyik?
	/// pc[0] = 's'; // Nem jó, konstansra mutat...
	pc++; // Jó, a pointer nem konstans

	// 7.
	char s2[] = "Szia!";
	char* const cp1 = s2; // Ez melyik?
	cp1[0] = 's'; // Jó, nem konstansra mutat...
	// cp1++; // Nem jó, a pointer konstans

	// 8.
	char s3[] = "Hello!";
	const char* const cp2 = s3; // Ez melyik?
	// cp2[0] = 's'; // Nem jó, konstanst nem tudunk módosítani
	// cp++; // Nem jó, a pointer konstans...

	// 9.
	int l = 0;
	// A konstans referencia valójában egy referencia egy konstansra.
	int const &m1 = l; // Referenciát alapból nem lehet megváltoztatni deklaráció után
	// m1 = 1; // Fordítási hiba. A const a hivatkozott értékre vonatkozik, amit nem lehet megváltoztatni.
	const int &m2 = l; // Ugyanaz
	// m2 = 1; // Fordítási hiba...

	// 10.
	// Paraméterátadásnál van szerepe a konstans referenciának
	// Amikor "nagy" objektumot szeretnénk paraméterként átadni, aminek azonban az értékét nem kívánjuk változtatni

	// void f(big_structure_type p);  // lassú, érték szerinti átadás
	// void f(big_structure_type& p); // gyors, de a paraméter megváltoztatható
	// void f(const big_structure_type& p); // megoldás!

	return 0;
}