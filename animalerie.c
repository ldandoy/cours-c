#include <stdio.h>
#include <string.h>

#define TAILLE 10 

typedef struct {
	char name[100];
	int age;
	char species[50];
	char color[20];
} animal;

void afficherMenu() {
	printf("Que voulez vous faire ?\n");
	printf("1- Lister les adoptions\n");
	printf("2- Ajouter un animal a l'adoption\n");
	printf("3- Adopter\n");
	printf("0- Quitter\n");
}

void listerAnimaux(animal animaux[], int nb) {
	printf("Listing:\n");
	if (nb == 0) {
		printf("Aucun animal disponible.\n");
		return;
	}
	for (int i = 0; i < nb; i++) {
		printf("- %s (%s, %d ans, %s)\n", 
			animaux[i].name, 
			animaux[i].species, 
			animaux[i].age, 
			animaux[i].color);
	}
}

int ajouterAnimal(animal animaux[], int nb) {
	if (nb >= TAILLE) {
		printf("L'animalerie est pleine!\n");
		return nb;
	}

	printf("Ajouter un animal\n");
	printf("Donnez son nom: ");
	scanf("%s", animaux[nb].name);
	printf("Donnez son age: ");
	scanf("%d", &animaux[nb].age);
	printf("Donnez sa race: ");
	scanf("%s", animaux[nb].species);
	printf("Donnez sa couleur: ");
	scanf("%s", animaux[nb].color);

	printf("Animal ajoute avec succes!\n");
	return nb + 1;
}

int adopterAnimal(animal animaux[], int nb) {
	if (nb == 0) {
		printf("Aucun animal disponible a l'adoption.\n");
		return nb;
	}

	char nom[100];
	printf("Quel animal voulez-vous adopter? Entrez son nom: ");
	scanf("%s", nom);

	for (int i = 0; i < nb; i++) {
		if (strcmp(animaux[i].name, nom) == 0) {
			printf("Felicitations! Vous avez adopte %s!\n", nom);
			// Decaler les animaux pour combler le trou
			for (int j = i; j < nb - 1; j++) {
				animaux[j] = animaux[j + 1];
			}
			return nb - 1;
		}
	}

	printf("Animal non trouve.\n");
	return nb;
}

int main(void)
{
	int choix;
	int nb = 0;
	animal animaux[TAILLE];

	printf("\nWelcome to Animals 2.0\n\n");

	do {
		afficherMenu();
		scanf("%d", &choix);

		switch(choix) {
			case 0:
				printf("Au revoir!\n");
				break;
			case 1:
				listerAnimaux(animaux, nb);
				break;
			case 2:
				nb = ajouterAnimal(animaux, nb);
				break;
			case 3:
				nb = adopterAnimal(animaux, nb);
				break;
			default:
				printf("Choix invalide.\n");
		}
		printf("\n");

	} while(choix != 0);

	return 0;
}
