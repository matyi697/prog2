#include <stdio.h>

double a(double aa)
{
	return 2 * aa;
}

double a(double aa)
{
	return aa / 2;
}

double a(double aa)
{
	return aa + 1;
}

double a(double aa)
{
	return a(a(a(a(a(aa)))));
}

int main()
{
	// az eredmény legyen 9
	printf("%.1lf\n", a(2));
	return 0;
}