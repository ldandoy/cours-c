// Exercice 2 : Gestion d'un accueil avec file et historique avec pile
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "pile.h"

// affichage d'une file d'entiers
void afficherFile(t_file *f){
    if(fileVide(f)){
        printf("File d'attente vide.\n");
        return;
    }
    printf("File d'attente : ");
    t_maillonF *temp = f->tete;
    while(temp != NULL){
        printf("%d ", *(int*)(temp->data));
        temp = temp->suivant;
    }
    printf("\n");
}

// affichage d'une pile d'entiers
void afficherPile(t_pile *p){
    if(pileVide(p)){
        printf("Historique vide.\n");
        return;
    }
    printf("Historique (du plus recent au plus ancien) : ");
    t_maillonP *temp = p->sommet;
    while(temp != NULL){
        printf("%d ", *(int*)(temp->data));
        temp = temp->suivant;
    }
    printf("\n");
}

int main(){
    t_file file;
    t_pile historique;
    int choix, numero;
    int *data;

    init_file(&file);
    init_pile(&historique);

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Ajouter un visiteur dans la file\n");
        printf("2 - Appeler le prochain visiteur\n");
        printf("3 - Afficher la file d'attente\n");
        printf("4 - Afficher l'historique des visiteurs traites\n");
        printf("5 - Annuler le dernier visiteur traite\n");
        printf("6 - Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                printf("Numero du visiteur : ");
                scanf("%d", &numero);
                data = malloc(sizeof(int));
                *data = numero;
                enfiler(&file, data);
                printf("Visiteur %d ajoute a la file.\n", numero);
                break;

            case 2:
                if(fileVide(&file)){
                    printf("Erreur : la file est vide, aucun visiteur a appeler.\n");
                } else {
                    data = defiler(&file);
                    printf("Visiteur %d appele au guichet.\n", *data);
                    empiler(&historique, data);
                }
                break;

            case 3:
                afficherFile(&file);
                break;

            case 4:
                afficherPile(&historique);
                break;

            case 5:
                if(pileVide(&historique)){
                    printf("Erreur : l'historique est vide, rien a annuler.\n");
                } else {
                    data = depiler(&historique);
                    printf("Visiteur %d remis dans la file.\n", *data);
                    enfiler(&file, data);
                }
                break;

            case 6:
                printf("Au revoir.\n");
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }
    } while(choix != 6);

    // Liberation memoire
    while(!fileVide(&file)){
        data = defiler(&file);
        free(data);
    }
    while(!pileVide(&historique)){
        data = depiler(&historique);
        free(data);
    }

    return 0;
}
