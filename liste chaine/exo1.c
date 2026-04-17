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

int main() {

    Noeud *head = malloc(sizeof(Noeud));
    Noeud *head1 = malloc(sizeof(Noeud));
    Noeud *head2 = malloc(sizeof(Noeud));

    head->value = 10;
    head1->value = 20;
    head2->value = 30;

    head->next = head1;
    head1->next = head2;
    head2->next = NULL;

    afficher(head);

    free(head);
    free(head1);
    free(head2);

    head=NULL;
    head1=NULL;
    head2=NULL;

    return 0;
}