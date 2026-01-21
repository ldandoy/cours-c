#include <stdio.h>
#include <stdlib.h>

float saisirReel(float min, float max) {
    float valeur;
    int retour;

    do {
        printf("Entrez un reel entre %.2f et %.2f : ", min, max);
        retour = scanf("%f", &valeur);

        // Vide le buffer en cas d'erreur (entrée non numérique)
        while (getchar() != '\n');

        if (retour != 1) {
            printf("Erreur : saisie non valide.\n");
            continue;
        }
        if (valeur < min || valeur > max) {
            printf("Erreur : valeur hors plage.\n");
        }
    } while (retour != 1 || valeur < min || valeur > max);

    return valeur;
}

int saisirEntierPair(int min, int max) {
    int valeur;
    int retour;

    do {
        printf("Entrez un entier pair entre %d et %d : ", min, max);
        retour = scanf("%d", &valeur);

        // Vide le buffer en cas d'erreur (entrée non numérique)
        while (getchar() != '\n');

        if (retour != 1) {
            printf("Erreur : saisie non valide.\n");
            continue;
        }
        if (valeur < min || valeur > max) {
            printf("Erreur : valeur hors plage.\n");
        } else if (valeur % 2 != 0) {
            printf("Erreur : le nombre doit etre pair.\n");
        }
    } while (retour != 1 || valeur < min || valeur > max || valeur % 2 != 0);

    return valeur;
}

int main(void) {
    float reel = saisirReel(-10.0, 10.0);
    printf("Vous avez saisi le reel : %.2f\n", reel);

    int pair = saisirEntierPair(0, 100);
    printf("Vous avez saisi l'entier pair : %d\n", pair);

    return 0;
}