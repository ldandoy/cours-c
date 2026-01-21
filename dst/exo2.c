#include <stdio.h>

int main(void) {
	int n;

	printf('Saisir un nombre entier:\n');
	scanf("%d", &n);

	for (int i=0; i<10; i++) {
		printf("%d x %d = %d", n, i, n*i);
	}

	return 0;
}