#include <stdio.h>

// Fonction pour calculer le PGCD avec l'algorithme d'Euclide
int pgcd(int a, int b) {
    while (b != 0) {
        int reste = a % b;
        a = b;
        b = reste;
    }
    return a;
}

int main(void) {
    int x, y;

    printf("Entrez le premier entier : ");
    scanf("%d", &x);

    printf("Entrez le deuxieme entier : ");
    scanf("%d", &y);

    printf("Le PGCD de %d et %d est : %d\n", x, y, pgcd(x, y));

    return 0;
}
