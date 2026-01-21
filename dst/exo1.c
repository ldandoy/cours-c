#include <stdio.h>

int main(void) {
	int e;

	printf("Saisir un nombre:");
	scanf("%d", &e);

	if (e%2 == 0) {
		printf("Votre entier est pair");
	} else {
		printf("Votre entier est impaire");
	}

	if (e>=0) {
		printf("Votre entier est positif");
	} else if (e==0) {
		printf("Votre entier est null");		
	} else {
		printf("Votre entier est négatif");
	}

	return 0;
}