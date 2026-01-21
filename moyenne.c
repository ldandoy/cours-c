/*
Écrire une fonction :

	float moyenne(const int *t, int taille);

qui calcule la moyenne des éléments du tableau en utilisant
uniquement la notation pointeur.

Le programme :
- Demande à l’utilisateur combien de valeurs il veut saisir.
- Remplit un tableau d’entiers.
- Appelle la fonction moyenne() et affiche le résultat.
*/

#include <stdio.h>

float moyenne(const int *t, int taille) {
    int somme = 0;
    const int *p = t; // pointeur sur le premier élément

    for (int i = 0; i < taille; i++) {
        somme += *(p + i); // ou somme += *p++;
    }
    return (float)somme / taille;
}

int main(void) {
    int n;
    printf("Combien de valeurs ? ");
    scanf("%d", &n);

    int tab[n];
    for (int i = 0; i < n; i++) {
        printf("Valeur %d : ", i + 1);
        scanf("%d", &tab[i]);
    }

    printf("La moyenne est : %.2f\n", moyenne(tab, n));

    return 0;
}
