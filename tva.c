#include <stdio.h>

int main(void) {
	// Définition des variables
	float prix_HT, montant_TVA, prix_TTC;
	int choix = 0;

	do { 

		// On demande à l'utilisateur le prix HT
		printf("Entez le prix HT: ");
		scanf("%f", &prix_HT);

		// On calcule la TVA
		montant_TVA = prix_HT * 0.20;

		// On calcule le prix TTC
		prix_TTC = prix_HT + montant_TVA;

		// On afficle les 3 prix
		// Sans les variables
		printf("Montant TVA: %.2f\n", prix_HT * 0.20);
		printf("Montant TTC: %.2f", prix_HT + (prix_HT * 0.20));

		// En utilisante les variables
		// printf("Montant TVA: %.2f\n", montant_TVA);
		// printf("Montant TTC: %.2f", prix_TTC);

		printf("\n\nVoulez-vous recommencer ?\n0- Non 1- Oui\n");
		scanf("%d", &choix);

	
	} while(choix == 1);

	return 0;
}