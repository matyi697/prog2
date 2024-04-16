#include <stdio.h>

void swapUsingPointers(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
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
	printf("1. pelda\n");
	int x;
	int& y = x;
	printf("\tx=%d; y=%d\n", x, y);

	// 2. példa
	printf("2. pelda\n");
	int u = 10;
	int v = 20;
	printf("\tu=%d; v=%d\n", u, v);
	swapUsingPointers(&u, &v);
	printf("\tu=%d; v=%d\n", u, v);

	// 3. példa
	printf("3. pelda\n");
	int i = 40;
	int j = 50;
	printf("\ti=%d; j=%d\n", i, j);
	swapUsingReferences(i, j);
	printf("\ti=%d; j=%d\n", i, j);

	// 4. példa
	printf("4. pelda\n");
	// - a localref olyan területre mutat, ami ugyan még tartalmazza a 10-es értéket, de már nem ez a program kezeli
	// - tehát memóriaszemétre mutat: nem bízhatunk abban, hogy ha bármikor kiolvassuk, mindig 10-et kapunk
	int& localref = getLocalVariable();
	printf("\tlocalref=%d\n", localref);
	localref = 44;
	printf("\tlocalref=%d\n", localref);
	printf("\tlocalref=%d\n", localref);
	printf("\tlocalref=%d\n", localref);

	// 5. példa
	printf("5. pelda\n");
	int k = 100;
	int& l = k;
	int& m = l;
	int& n = m = 200;
	printf("\tk=%d; l=%d; m=%d; n=%d\n", k, l, m, n);

	// 6. példa
	printf("6. pelda\n");
	int* o = new int;
	*o = 700;
	int& p = *o;
	printf("\to=%d; p=%d\n", *o, p);

	delete o; // dinamikusan foglalt területet fel kell szabadítani, különben => while(--pontok); // :(

	return 0;
}