#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

Noeud* ajouterDebut(Noeud *tete, int valeur) {

    Noeud *nouveau = malloc(sizeof(Noeud));

    nouveau->valeur = valeur;
    nouveau->suivant = tete;

    return nouveau;
}

void afficher(Noeud *tete) {
    while (tete != NULL) {
        printf("%d -> ", tete->valeur);
        tete = tete->suivant;
    }
    printf("NULL\n");
}

int main() {

    Noeud *tete = NULL;
    int n, val;

    printf("Combien de valeurs ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valeur : ");
        scanf("%d", &val);
        tete = ajouterDebut(tete, val);
    }

    afficher(tete);

    return 0;
}