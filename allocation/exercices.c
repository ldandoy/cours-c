// Exercice 1 — Allocation dynamique d’un entier
/*
Écrire un programme en C qui :
Alloue dynamiquement un entier.
Demande à l’utilisateur de saisir une valeur entière.
Stocke cette valeur dans la zone mémoire allouée.
Affiche la valeur saisie.
Libère la mémoire avant la fin du programme.
*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p, *b;

    // Allocation dynamique
    p = (int *)malloc(sizeof(int));

    if (p == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    // Saisie
    printf("Entrez un entier : ");
    scanf("%d", p);

    // Affichage
    printf("Valeur saisie : %d\n", *p);

    // Liberation de la memoire
    free(p);
    p = NULL;

    return 0;
}

// Exercice 2 — Allocation dynamique de deux entiers
/*
Alloue dynamiquement deux entiers.
Demande à l’utilisateur de saisir deux valeurs entières.
Calcule et affiche :
la somme,
le produit.
Libère la mémoire allouée.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a, *b;

    a = malloc(sizeof(int));
    b = malloc(sizeof(int));

    if (a == NULL || b == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    printf("Entrez le premier entier : ");
    scanf("%d", a);

    printf("Entrez le second entier : ");
    scanf("%d", b);

    printf("Somme : %d\n", *a + *b);
    printf("Produit : %d\n", (*a) * (*b));

    free(a);
    free(b);

    return 0;
}

// EXercice 3 - Passage des variables aux fonctions
/*
Transformer le code précedent en utilisant une fonction pour
effectuer la somme avec un return.
*/
