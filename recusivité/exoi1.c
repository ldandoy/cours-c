/*
Écrire une fonction récursive qui affiche les nombres de N (entier 
positif) jusqu’à 1.

Exemple :

Entrez un nombre N: 5

5
4
3
2
1

Contraintes :
- la fonction doit être récursive
- on ne doit pas utiliser de boucle
*/

#include <stdio.h>

void compter(int n) {
    if (n <= 0) {
        return;
    }
    printf("%d\n", n);
    compter(n - 1);
}

int main() {
    int n;
    printf("Entrez un nombre N: ");
    scanf("%d", &n);
    compter(n);
    return 0;
}