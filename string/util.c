#include <stdio.h>
#include <string.h>

void afficher(char *text) {
	printf("Contenu recu: %s", text);
}

void compteur_mot(char *text) {
	int nb_mot = 0;
	int i = 0;

	while(text[i] != '\0') {
		if (text[i] == ' ') {
			nb_mot++;
		}
		i++;
	}

	if (i > 0) {
		nb_mot++;
	}

	printf("Il y a %d mots", nb_mot);
}