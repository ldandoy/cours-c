/*
Ecrire un programme :
	• Demande à l’utilisateur combien de valeurs il souhaite saisir (N ≤ 100).
	• Saisit les N valeurs entières dans un tableau.

Calcule et affiche :
	• la moyenne des valeurs,
	• le nombre de valeurs supérieures à la moyenne.
*/

#include <stdio.h>

int main(void) {
    int n;                // nombre de valeurs à saisir
    int tab[100];         // tableau pour stocker les valeurs (max 100)
    int i;                // compteur de boucle
    int somme = 0;        // pour calculer la somme des valeurs
    float moyenne;        // pour stocker la moyenne
    int sup = 0;          // compteur des valeurs supérieures à la moyenne

    // --- Saisie du nombre de valeurs ---
    do {
        printf("Combien de valeurs souhaitez-vous saisir (1 à 100) ? ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    // --- Saisie des valeurs ---
    for (i = 0; i < n; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &tab[i]);
        somme += tab[i];
    }

    // --- Calcul de la moyenne ---
    moyenne = (float)somme / n;

    // --- Comptage des valeurs supérieures à la moyenne ---
    for (i = 0; i < n; i++) {
        if (tab[i] > moyenne) {
            sup++;
        }
    }

    // --- Affichage des résultats ---
    printf("\nMoyenne : %.2f\n", moyenne);
    printf("Nombre de valeurs superieures a la moyenne : %d\n", sup);

    return 0;
}
