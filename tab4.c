/*
Écrire un programme en C qui :
	• Demande à l’utilisateur de remplir un tableau de 10 entiers.
	• Demande ensuite une valeur à recherher.

Affiche :
	• si la valeur est présente ou non,
	• et si oui, à quelle position (index ou numéro d’ordre).
*/
#include <stdio.h>

#define N 10  // taille fixe du tableau

int main(void) {
    int tab[N];
    int valeur;
    int i;
    int trouve = 0; // drapeau (0 = non trouvé, 1 = trouvé)

    // --- Remplissage du tableau ---
    printf("Remplissez le tableau de %d entiers :\n", N);
    for (i = 0; i < N; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &tab[i]);
    }

    // --- Saisie de la valeur à rechercher ---
    printf("\nEntrez la valeur a rechercher : ");
    scanf("%d", &valeur);

    // --- Recherche dans le tableau ---
    for (i = 0; i < N; i++) {
        if (tab[i] == valeur) {
            printf("Valeur trouvee a la position %d (index %d)\n", i + 1, i);
            trouve = 1;
        }
    }

    // --- Si la valeur n’est pas trouvée ---
    if (!trouve) {
        printf("Valeur non trouvee dans le tableau.\n");
    }

    return 0;
}
