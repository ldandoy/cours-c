#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "pile.h"

void afficherFile(t_file *f){
    printf("File : ");
    t_maillonF *temp = f->tete;
    while(temp != NULL){
        printf("%d ", *(int*)(temp->data));
        temp = temp->suivant;
    }
    printf("\n");
}

void afficherPile(t_pile *p){
    printf("Pile : ");
    t_maillonP *temp = p->sommet;
    while(temp != NULL){
        printf("%d ", *(int*)(temp->data));
        temp = temp->suivant;
    }
    printf("\n");
}

int main (void) {
    int *data;

    t_file fileInitiale, fileFinale;
    t_pile pile;

    init_file(&fileInitiale);
    init_file(&fileFinale);
    init_pile(&pile);

    for(int i = 1; i <= 4; i++){
        data = malloc(sizeof(int));
        *data = i;
        enfiler(&fileInitiale, data);
    }

    printf("=== Etape 1 : File initiale ===\n");
    afficherFile(&fileInitiale);

    while(!fileVide(&fileInitiale)){
        data = defiler(&fileInitiale);
        empiler(&pile, data);
    }

    printf("\n=== Etape 2 : Contenu de la pile ===\n");
    afficherPile(&pile);

    while(!pileVide(&pile)){
        data = depiler(&pile);
        enfiler(&fileFinale, data);
    }

    printf("\n=== Etape 3 : File finale (inversee) ===\n");
    afficherFile(&fileFinale);

    while(!fileVide(&fileFinale)){
        data = defiler(&fileFinale);
        free(data);
    }

    return 0;
}