#include <stdlib.h>
#include <stdio.h>
main() {
	void* p; // ciklusban nem lehet deklarálni
	while (1) {
		// malloc(): csak egy "igényt" nyújt be az operációs rendszer felé hogy X egybefüggő bájtot szeretne használni.
		// Ha van még szabad memória, ad neki, de nem foglalja le ténylegesen, csak ha el is kezdi használni.
		// Éppen ezért nem fog látszódni feladatkezelőben (CTRL+ALT+DEL) hogy elfogy a memória.
		// Azonban az oprendszer előre gondolkodik és számít rá, hogy fogom használni azt a sok-sok memóriát amire igényt nyújtottam be,
		// ezért ha olyan igényt nyújtanék be, amit már később esetleg nem tudna teljesíteni, NULL-t ad vissza.
		// calloc(): a malloc()-kal szemben használatba veszi a memóriát (csupa nullát ÍR bele), tehát látszódni is fog feladatkezelőben hogy lefoglalta.

		//p = malloc(1024); // igény
		p = calloc(1024, sizeof(double)); // igény+használat
		if (p!=NULL) // ha sikerült lefoglalni
			printf("memory allocation: %p\n", p); // kiírjuk a terület első bájtjának címét
		else printf("cant allocate\n"); // különben kiírjuk, hogy nem tudott lefoglalni
	}
}