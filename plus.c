#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
	srand(time(NULL));

	int choix, input = 0;
	int retour;

	printf("===================\n");
	printf(" Plus ou Moins\n");
	printf("===================\n");

	do {
		int guess = rand() % 100;
		int tries = 0;
		printf("Chiffre à trouver: %i\n", guess);

		do {
			printf("Trouver le chiffre mystère entre 0 et 100:\n");
			retour = scanf("%i",&input);


			// Vide le buffer en cas d'erreur (entrée non numérique)
	        while (getchar() != '\n');

	        if (retour != 1) {
	            printf("Erreur : saisie non valide.\n");
	            continue;
	        }

	        if (input < 0 || input > 100) {
	            printf("Erreur : valeur hors plage.\n");
	        }

			if (input > guess) {
				printf("Le chiffre à trouver est plus petit !\n");
			} else if (input < guess) {
				printf("Le chiffre à trouver est plus grand !\n");
			}

			tries ++;

		} while(input != guess);


		if (input == guess) {
			printf("Bravo vous avez trouvé en %i essais !\n\n", tries);
		}

		printf("Voulez vous rejouer ?\n");
		printf("0 - Non 1- Oui\n");
		scanf("%i", &choix);
	} while (choix != 0);

	return 0;
}