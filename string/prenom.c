#include <stdio.h>

int main(void) {
	char prenom[100];
	char search[] = "aeiouy";
	int nb = 0;
	int nb_voyelle = 0;

	printf("Entrez votre prénom:");
	scanf("%99s", prenom);

	printf("Bonjour %s !\n", prenom);

	for(int i=0; prenom[i] != '\0' ;i++) {
		nb ++;

		for(int v=0; search[v] != '\0'; v++) {
			if (search[v] == prenom[i]) {
				nb_voyelle ++;
				break;
			}
		}
	}

	printf("Il y a %d caratères\n", nb);
	printf("Il y a %d voyelles\n", nb_voyelle);

	return 0;
}