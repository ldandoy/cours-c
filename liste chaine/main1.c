#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

void afficher(Noeud *tete) {
    Noeud *courant = tete;

    while (courant != NULL) {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

int main() {

    // Création des 3 noeuds
    Noeud *n1 = malloc(sizeof(Noeud));
    Noeud *n2 = malloc(sizeof(Noeud));
    Noeud *n3 = malloc(sizeof(Noeud));

    n1->valeur = 10;
    n2->valeur = 20;
    n3->valeur = 30;

    n1->suivant = n2;
    n2->suivant = n3;
    n3->suivant = NULL;

    afficher(n1);

    return 0;
}