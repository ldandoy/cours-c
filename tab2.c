/*
Ecrire un programme :
	• Demande à l’utilisateur combien de valeurs il souhaite saisir (N ≤ 100).
	• Saisit les N valeurs entières dans un tableau.

Calcule et affiche :
	• la moyenne des valeurs,
	• le nombre de valeurs supérieures à la moyenne.
*/

#include <stdio.h>

int nb_notes_supp_moyenne(int *tab, int n, float moyenne) {
	int nb = 0;

	for (int i=0; i<n; i++) {
		if (tab[i] >= moyenne) {
			nb ++;
		}
	}

	return nb;
}

float calcule_moyenne(const int *tab, int n) {
	float moyenne=0.0;

	for (int i=0; i<n; i++) {
		moyenne = moyenne + tab[i]; 
	}

	return moyenne/n;
}

int main(void) {
	int n, nb_notes;
	float moyenne = 0.0;
	int tab[100];

	printf("Combien de valeur voulez vous saisir ?\n");
	scanf("%d", &n);

	if (n < 0 || n >= 100) {
		printf("Attention vous devez saisir un chiffre entre 1 et 100.");
		return 1;
	}

	for (int i = 0; i< n; i++) {
		printf("Entrez la valuer %d :\n", i+1);
		scanf("%d", &tab[i]);
	}

	moyenne = calcule_moyenne(tab, n);
	printf("Moyenne: %.2f\n", moyenne);

	nb_notes = nb_notes_supp_moyenne(tab, n, moyenne);
	printf("Nombre notes suppérieur à la moyenne: %d\n", nb_notes);

	return 0;
}