#include <stdio.h>

// függvénypointer, ami olyan függvényre mutat, amely két konstans int pointert vár paraméterül
typedef int(*OperationFunction)(const int*, const int*);

typedef struct {
	char const *operation; // az műveleti jelet ebben tároljuk
	OperationFunction pfv; // az műveletet elvégző függvényre mutatunk
} Operation;

int add(const int* a, const int* b) {
	return *a + *b;
}

int multiply(const int* a, const int* b) {
	return *a**b;
}

int power(const int* a, const int* b) {
	int result = 1;
	for (int i = 0; i < *b; ++i)
		result *= *a;

	return result;
}

Operation operations[] = {
	{ "+", add },
	{ "*", multiply },
	{ "^", power },
	{ nullptr, nullptr }   // null terminator
};

int main() {

	int a, b;
	printf("Enter two integers in this format \"a b\" : ");
	scanf_s("%d %d", &a, &b);

	for (int i = 0; operations[i].operation != NULL; ++i)
		printf("%d%s%d = %d\n", a, operations[i].operation, b, operations[i].pfv(&a, &b));

	return 0;
}