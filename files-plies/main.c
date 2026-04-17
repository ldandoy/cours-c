// Exercice : Inverser une file avec une pile
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "pile.h"

// affichage d'une file d'entiers
void afficherFile(t_file *f){
    printf("File : ");
    t_maillonF *temp = f->tete;
    while(temp != NULL){
        printf("%d ", *(int*)(temp->data));
        temp = temp->suivant;
    }
    printf("\n");
}

// affichage d'une pile d'entiers
void afficherPile(t_pile *p){
    printf("Pile : ");
    t_maillonP *temp = p->sommet;
    while(temp != NULL){
        printf("%d ", *(int*)(temp->data));
        temp = temp->suivant;
    }
    printf("\n");
}

int main(){
    int i;
    int *data;
    t_file fileInitiale, fileFinale;
    t_pile pile;

    init_file(&fileInitiale);
    init_file(&fileFinale);
    init_pile(&pile);

    // 1) Remplir la file initiale avec 1, 2, 3, 4
    for(i = 1; i <= 4; i++){
        data = malloc(sizeof(int));
        *data = i;
        enfiler(&fileInitiale, data);
    }

    printf("=== Etape 1 : File initiale ===\n");
    afficherFile(&fileInitiale);

    // 2) Transferer la file dans la pile (defiler puis empiler)
    while(!fileVide(&fileInitiale)){
        data = defiler(&fileInitiale);
        empiler(&pile, data);
    }

    printf("\n=== Etape 2 : Contenu de la pile ===\n");
    afficherPile(&pile);

    // 3) Transferer la pile dans la file finale (depiler puis enfiler)
    while(!pileVide(&pile)){
        data = depiler(&pile);
        enfiler(&fileFinale, data);
    }

    printf("\n=== Etape 3 : File finale (inversee) ===\n");
    afficherFile(&fileFinale);

    // Liberation memoire
    while(!fileVide(&fileFinale)){
        data = defiler(&fileFinale);
        free(data);
    }

    return 0;
}
