#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonction qui simule un lancer de dé à 6 faces
int lancer_de6(void) {
    return rand() % 6 + 1; // valeur entre 1 et 6
}

int main(void) {
    // Initialisation du générateur aléatoire avec l'heure courante
    srand(time(NULL));

    printf("Lancer de dé : %d\n", lancer_de6());
    printf("Lancer de dé : %d\n", lancer_de6());
    printf("Lancer de dé : %d\n", lancer_de6());

    return 0;
}