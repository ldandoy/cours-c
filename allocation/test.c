#include <stdio.h>
#include <stdlib.h>

int somme(int *a, int *b) {
    return *a + *b;
}

int main(void) {
    int *a, *b;
    int resultat;

    // Allocation dynamique
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));

    if (a == NULL || b == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    // Saisie
    printf("Entrez le premier entier : ");
    scanf("%d", a);

    printf("Entrez le second entier : ");
    scanf("%d", b);

    // Appel de la fonction
    resultat = somme(a, b);

    // Affichage
    printf("Somme : %d\n", resultat);
    printf("Produit : %d\n", (*a) * (*b));

    // Liberation de la memoire
    free(a);
    free(b);

    a = NULL;
    b = NULL;

    return 0;
}