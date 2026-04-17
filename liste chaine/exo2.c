#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int value;
    struct Noeud *next;
} Noeud;

void afficher (Noeud *head) {
    if (head == NULL) {
        return;
    }

    printf("%d\n", head->value);

    afficher(head->next);
}

Noeud* ajouterDebut(Noeud *head, int valeur) {
    Noeud *newNoeud = malloc(sizeof(Noeud));
    newNoeud->value = valeur;
    newNoeud->next = head;

    return newNoeud;
}

int main() {

    Noeud *head = malloc(sizeof(Noeud));
    int nb;
    int valeur;

    printf("Combien de valeurs voulez vous: ");
    scanf("%d", &nb);

    for(int i=0; i<nb; i++) {
        printf("Entez la valeur %d: ", i);
        scanf("%d", &valeur);

        head = ajouterDebut(head, valeur);
    }
    

    afficher(head);

    free(head);
    head=NULL;

    return 0;
}