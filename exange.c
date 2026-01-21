/*
Écrire un programme qui :
- Déclare deux entiers a et b.
- Demander les valeurs à l'utilisateur
- Affiche leurs valeurs avant l’échange.
- Appelle la fonction echanger(&a, &b);.
- Affiche leurs valeurs après l’échange.
*/

#include <stdio.h>

// Fonction : echanger
// Rôle : échanger les valeurs pointées par x et y
// Entrées -> int *x, int *y
// Sortie -> aucune (effet de bord)
void echanger(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    int a = 5, b = 9;

    printf("Avant echange : a = %d, b = %d\n", a, b);
    echanger(&a, &b);
    printf("Apres echange : a = %d, b = %d\n", a, b);

    return 0;
}
