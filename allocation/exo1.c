#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int *p;

    // Allocation dynamique
    p = (int *)malloc(sizeof(int));

    if (p == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    // Saisie
    printf("Entrez un entier : ");
    scanf("%d", p);

    // Affichage
    printf("Valeur saisie : %d\n", *p);

    // Liberation de la memoire
    free(p);
    p = NULL;

    return 0;
}