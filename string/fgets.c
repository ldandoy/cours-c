#include <stdio.h>
#include "util.h"

#define TAILLE 100


int main (void) {
	char message[TAILLE];

	printf("Entrez une phrase : ");
	fgets(message, TAILLE, stdin);

	afficher(message);
	compteur_mot(message);
	
	return 0;
}