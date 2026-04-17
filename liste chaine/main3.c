#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

Noeud* ajouterDebut(Noeud *tete, int val) {
    Noeud *n = malloc(sizeof(Noeud));
    n->valeur = val;
    n->suivant = tete;
    return n;
}

Noeud* supprimer(Noeud *tete, int val) {

    // Cas : suppression en tête
    if (tete != NULL && tete->valeur == val) {
        Noeud *tmp = tete;
        tete = tete->suivant;
        free(tmp);
        return tete;
    }

    Noeud *courant = tete;

    while (courant != NULL && courant->suivant != NULL) {

        if (courant->suivant->valeur == val) {
            Noeud *tmp = courant->suivant;
            courant->suivant = tmp->suivant;
            free(tmp);
            return tete;
        }

        courant = courant->suivant;
    }

    printf("Valeur non trouvee\n");
    return tete;
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

    printf("Valeur a supprimer : ");
    scanf("%d", &val);

    tete = supprimer(tete, val);

    afficher(tete);

    return 0;
}