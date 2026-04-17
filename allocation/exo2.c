#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a, *b;

    a = malloc(sizeof(int));
    b = malloc(sizeof(int));

    if (a == NULL || b == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    printf("Entrez le premier entier : ");
    scanf("%d", a);

    printf("Entrez le second entier : ");
    scanf("%d", b);

    printf("Somme : %d\n", *a + *b);
    printf("Produit : %d\n", (*a) * (*b));

    free(a);
    free(b);

    return 0;
}
