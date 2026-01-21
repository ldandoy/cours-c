// inclusion de la librairie stdio pour utiliser les fonction de saisie et d'affichage
#include <stdio.h>

int main() {
    int duree_heures, duree_minutes;
    int heures, minutes, secondes;
    int duree_secondes;
    int reste;
    int choix;

    /*affichage d'un menu et récupération du choix de l'utilisateur*/
    printf("\n1. convertir des h,m,s en secondes ");
    printf("\n2. convertir des secondes en h,m,s\n");
    scanf("%d",&choix);
    printf("%d", choix);
    /*orientation du programme en fonction du choix*/
    if(choix==1){
        printf("nombre d'heures : ");
        scanf("%d",&heures);
        printf("nombre de minutes : ");
        scanf("%d",&minutes);
        printf("nombre de secondes : ");
        scanf("%d",&secondes);
        duree_secondes=heures*3600+minutes*60+secondes;
        printf("\nla duree totale en secondes est : %d\n",duree_secondes);
    }
    else{
        if(choix==2){
            printf("\nNombre de secondes à convertir: ");
            
            if (scanf("%d", &secondes) != 1 || secondes < 0) {
                printf("Entree invalide (doit etre >= 0).\n"); return 1;
            }
            // scanf("%d", &secondes);

            duree_heures = secondes / 3600;
            // printf("%d\n", duree_heures); //vérification de la durée des heures 
            duree_minutes = (secondes % 3600) / 60;
            // printf("%d\n", duree_minutes); //vérification de la durée des minutes
            duree_secondes = secondes % 60;
            //printf("%d\n", duree_secondes); //vérification du reste de seconde
            printf("\nLa conversion de %d secondes est : %dh %dm et %ds",secondes,duree_heures,duree_minutes,duree_secondes);

        }
        else printf("choix invalide");
    }
    return 0;
}
