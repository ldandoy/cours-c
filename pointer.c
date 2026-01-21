/*
Écrire un programme en C qui :
- Déclare une variable entière a et un pointeur vers un entier p.
- Affecte à a une valeur (ex. 10).
- Fait pointer p vers a.

Affiche :
- la valeur de a,
- l’adresse de a,
- la valeur du pointeur p,
- la valeur pointée par p (*p).

Modifie la valeur de a via le pointeur (par exemple *p = 20;)
puis affiche à nouveau a et *p pour constater que les deux changent.
*/

#include <stdio.h>

int main(void) {
    int a = 10;
    int *p = NULL; // pointeur initialisé à NULL

    // 1. Faire pointer p sur a
    p = &a;

    // 2. Afficher les valeurs
    printf("Valeur de a : %d\n", a);
    printf("Adresse de a : %p\n", &a);
    printf("Valeur de p (adresse contenue) : %p\n", p);
    printf("Valeur pointée par p : %d\n", *p);

    // 3. Modifier a via p
    *p = 20;

    // 4. Afficher à nouveau
    printf("\nAprès modification via le pointeur :\n");
    printf("Valeur de a : %d\n", a);
    printf("Valeur pointée par p : %d\n", *p);

    return 0;
}
