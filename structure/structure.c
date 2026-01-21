#include <stdio.h>
#include <string.h>
#include <windows.h>

// Définition
typedef struct {
    char nom[30];
    int age;
} Contact;

int main(void) {
    // Déclaration
    Contact contacts[10] = {
        {nom: "", age: 0},
        {nom: "", age: 0},
        {nom: "", age: 0},
        {nom: "", age: 0},
        {nom: "", age: 0},
        {nom: "", age: 0},
        {nom: "", age: 0},
        {nom: "", age: 0},
        {nom: "", age: 0},
        {nom: "", age: 0},
    };
    int choix = 0;
    int index = 0;
    system("clear");

    do {
        printf("Que voulez vous faire ?\n");
        printf("2 - Afficher les contacts\n");
        printf("1 - Ajouter un contact\n");
        printf("0 - Quitter\n");
        scanf("%d", &choix);

        if (choix == 1) {
            system("clear");
            printf("Quel est le nom:");
            scanf("%s", &contacts[index].nom);
            printf("Quel est le nom:");
            scanf("%d", &contacts[index].age);
            index++;
            system("clear");
        } else if (choix == 2) {
            system("clear");
            // Utilisation
            for (int i = 0;i<10;i++) {
                if (strcmp(contacts[i].nom, "")) {
                    printf("- %s a %d ans\n", contacts[i].nom, contacts[i].age);
                }
            }

            printf("\n");
        }

    } while (choix != 0);

    return 0;
}