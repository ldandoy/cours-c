/*
Écrire une fonction récursive qui calcule la somme des éléments d’un tableau.

Prototype :

int somme(int *tab, int n);
tab : tableau d’entiers
n : nombre d’éléments



Exemple :

Combien d'elements: 4

tableau : 3 7 2 5

résultat = 17

Contraintes :
- utiliser une fonction récursive
- ne pas utiliser de boucle
*/

#include <stdio.h>

int somme(int *tab, int n) {

    if (n == 0)
        return 0;

    return tab[n-1] + somme(tab, n-1);
}

int main() {

    int tab[4] = {3,7,2,5};

    int result = somme(tab, 4);

    printf("Somme = %d\n", result);

    return 0;
}