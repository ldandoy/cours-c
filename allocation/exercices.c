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

// Exercice 4 — Tableau dynamique d’entiers
/*
Écrire un programme en C qui :
Demande à l’utilisateur combien de valeurs il souhaite saisir (N > 0).
Alloue dynamiquement un tableau de N entiers.
Saisit les N valeurs dans le tableau.
Calcule et affiche :
la somme,
la moyenne.
Libère la mémoire allouée.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *tab;
    int somme = 0;

    // Saisie de la taille
    do {
        printf("Combien de valeurs ? ");
        scanf("%d", &n);
    } while (n <= 0);

    // Allocation dynamique du tableau
    tab = (int *)malloc(n * sizeof(int));

    if (tab == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    // Saisie des valeurs
    for (int i = 0; i < n; i++) {
        printf("Valeur %d : ", i + 1);
        scanf("%d", &tab[i]);
        somme += tab[i];
    }

    // Calcul et affichage
    printf("Somme : %d\n", somme);
    printf("Moyenne : %.2f\n", (float)somme / n);

    // Liberation de la memoire
    free(tab);

    return 0;
}

// A retenir
/*
malloc()
malloc signifie memory allocation. Elle réserve un bloc de mémoire 
contigu d’une taille donnée, exprimée en octets.

calloc()
calloc (contiguous allocation) fonctionne comme malloc, mais avec 
deux différences :
— elle alloue la mémoire pour plusieurs éléments à la fois ;
— elle initialise tout à zéro.

void *realloc(void *ptr, size_t nouvelleTaille);
realloc permet de redimensionner un bloc alloué par malloc ou 
calloc. Elle est utile lorsqu’on souhaite agrandir ou réduire un 
tableau en cours d’exécution.

void free(void *ptr);
free() libère un bloc mémoire précédemment alloué. Elle rend 
l’espace au système d’exploitation pour qu’il puisse être réutilisé.
*/