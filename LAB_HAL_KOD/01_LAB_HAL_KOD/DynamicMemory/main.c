#include <stdio.h>
#include <stdlib.h>

int main() {

	//// A deklarációk a függvény elején vannak (ez csak C-re igaz)

	double* pMyDoubleArray = (double*)malloc(sizeof(double) * 10); // Dinamikus 1D tömb
	int* pMyInt = (int*)malloc(sizeof(int)); // Dinamikus primitív változó; ugyanígy a többire (double, float, ...)
	char* pMyCharArray = (char*)malloc(sizeof(char) * 10 + 1); // Dinamikus 1D char tömb (C string); 10 hasznos karakter +1 null terminátor
	int** pMy2dArray = (int**)malloc(sizeof(int*) * 10); // Dinamikus 2D int tömb; először a sorokra mutató mutatóknak foglalunk

	// ciklusváltozók
	int i, rowId, row, col;

	//// Innentől már nem lehet deklaráció, csak definíció

	if (pMyInt == NULL) return -1; // ha nem sikerült volna a foglalás (pl. elfogyott a memória)
	*pMyInt = 10;
	printf("pMyInt=%d\n", *pMyInt);
	free(pMyInt); // "Aki malloc()-ot mond, mondjon free()-t is!" ~ Dr. CZ; tehát ha nem szabadítjátok fel a dinamikusan lefoglalt memóriaterületet => while(--pontok);
	printf("pMyInt=%d\n", *pMyInt);
	

	if (pMyDoubleArray == NULL)
		return -1;
	for (i = 0; i < 10; i++) {
		pMyDoubleArray[i] = i*3.14;
		printf("pMyDoubleArray[%d]=%lf\n", i, pMyDoubleArray[i]);
	}

	
	if (pMyCharArray == NULL)
		return -1;
	strcpy(pMyCharArray, "abcdefghij");
	printf("pMyCharArray=%s\n", pMyCharArray);
	free(pMyCharArray);

	printf("pMy2dArray[][]:\n");
		// inicializálás
		for (rowId = 0; rowId < 10; rowId++)
			pMy2dArray[rowId] = (int*)malloc(sizeof(int) * 20);

		// használat
		for (row = 0; row < 10; row++) {
			for (col = 0; col < 20; col++) {
				pMy2dArray[row][col] = row*col;
				printf("%d ", pMy2dArray[row][col]);
			}
			printf("\n");
		}

		// felszabadítás!
		for (row = 0; row < 10; row++)
			free(pMy2dArray[row]);
		free(pMy2dArray);

	return 0;
}