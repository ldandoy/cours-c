#include <stdio.h>

int test (int a, int toto) {
	printf("toto: %i\n", toto);

	return a + toto;
}

int main(void) {
	int a;

	a = test(4, 6);
	printf("%i", a);

	return 0;
}
