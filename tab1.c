/*
Ecrire un programme :
	• Déclarer un tableau de N entiers
	• En utilisant une boucle et un pointeur pour passer de case en case, remplir le tableau
	avec des valeurs aléatoires dans l’intervalle [-10,10]
	• Afficher le tableau
*/

#include <stdio.h>
#include <stdlib.h> // pour rand(), srand()
#include <time.h>   // pour time()

#define N 10  // taille du tableau

int main(void) {
    int tab[N];
    int *p;  // pointeur pour parcourir le tableau

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    printf("Remplissage du tableau avec des valeurs aleatoires dans [-10, 10] :\n");

    // Remplir le tableau avec une boucle et un pointeur
    p = tab;  // le pointeur pointe sur le premier élément
    for (int i = 0; i < N; i++) {
        *p = (rand() % 21) - 10; // valeurs entre -10 et 10
        p++; // on avance le pointeur vers l’élément suivant
    }

    // Afficher le tableau
    printf("\nContenu du tableau : ");
    p = tab; // on remet le pointeur au début
    for (int i = 0; i < N; i++) {
        printf("%d ", *p); // afficher la valeur pointée
        p++;
    }
    printf("\n");

    return 0;
}
