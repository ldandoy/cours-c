/*
Combien de valeurs ? 5
Valeurs : 10 7 4 9 20

Somme = 50
Moyenne = 10.00
Valeurs paires = 3
Maximum = 20
*/

#include <stdio.h>

int main (void) {
	int nbValeurs = 0;
	int somme = 0;
	int paires = 0;
	int maxi = 0;
	printf("Combien de valeur ?");
	scanf("%d", &nbValeurs);

	printf("Valeurs:");


	printf("\n\nSomme: %d", somme);
	printf("\nMoyenne: %d", somme/nbValeurs);
	printf("\nValeurs paires: %d", paires);
	printf("\nMaximum: %d", maxi);


	return 0;
}
