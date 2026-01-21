#include <stdio.h>

int main() {
    char nom[50];
    int age;

    printf("Entrez votre nom : ");
    fgets(nom, sizeof(nom), stdin);  // lit une ligne entière (avec espaces)
    // scanf("%49s", nom);  // %49s pour éviter de dépasser la taille du tableau

    printf("Entrez votre age : ");
    scanf("%d", &age);

    printf("\nBonjour %s", nom);

    if (age >= 18) {
        printf("Vous etes majeur.\n");
    } else {
        printf("Vous etes mineur.\n");
    }

    return 0;
}
