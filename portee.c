#include<stdio.h>

int add(int a, int b) {
	int x = a + b;

	printf("x dans add: %i\n", x);

	return x;
}

int main() {
	int x = 10;
	printf ("Premier x dans main: %i\n", x);

	printf("x de add dans main: %i\n", add(6, 9));

	printf("Deuxieme x dans main: %i", x);
}