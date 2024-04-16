#include <iostream>

void swapUsingPointers(int* a, int* b) {
	int* temp = a;
	a = b;
	b = a;
}

void swapUsingReferences(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int& getLocalVariable() { // referenciát lokális változóra SOSE ADJATOK VISSZA! => while(--pontok);
	int a = 10;
	return a; // warning: returning address of local variable or temporary: a
	// ezen a ponton az 'a' lokális változó már felszabadult a call stack framen
}

int main(int argv, char*argc[]) {
	// 1. példa
	std::cout << "1. pelda" << std::endl;
	int x;
	int& y = x;
	std::cout << "\tx=" << x << "; y=" << y << std::endl;

	// 2. példa
	std::cout << "2. pelda" << std::endl;
	int u = 10;
	int v = 20;
	std::cout << "\tu=" << u << "; v=" << v << std::endl;
	swapUsingPointers(&u, &v);
	std::cout << "\tu=" << u << "; v=" << v << std::endl;

	// 3. példa
	std::cout << "3. pelda" << std::endl;
	int i = 40;
	int j = 50;
	std::cout << "\ti=" << i << "; j=" << j << std::endl;
	swapUsingReferences(i, j);
	std::cout << "\ti=" << i << "; j=" << j << std::endl;

	// 4. példa
	std::cout << "4. pelda" << std::endl;
	// - a localref olyan területre mutat, ami ugyan még tartalmazza a 10-es értéket, de már nem ez a program kezeli
	// - tehát memóriaszemétre mutat: nem bízhatunk abban, hogy ha bármikor kiolvassuk, mindig 10-et kapunk
	int& localref = getLocalVariable();
	std::cout << "\tlocalref=" << localref << std::endl;
	localref = 44;
	std::cout << "\tlocalref=" << localref << std::endl;
	std::cout << "\tlocalref=" << localref << std::endl;
	std::cout << "\tlocalref=" << localref << std::endl;

	// 5. példa
	std::cout << "5. pelda" << std::endl;
	int k = 100;
	int& l = k;
	int& m = l;
	int& n = m = 200;
	std::cout << "\tk=" << k << "; l=" << l << "; m=" << m << "; n=" << n << std::endl;

	// 6. példa
	std::cout << "6. pelda" << std::endl;
	int* o = new int;
	*o = 700;
	int& p = *o;
	std::cout << "\to=" << *o << "; p=" << p << std::endl;

	delete o; // dinamikusan foglalt területet fel kell szabadítani, különben => while(--pontok); // :(

	return 0;
}