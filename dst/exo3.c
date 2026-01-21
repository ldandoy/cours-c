#include <stdio.h>

void rendu(int montant) {
	int billet50=0, billet20=0, billet10=0;

	while(montant != 0) {
		while(montant >= 50) {
			montant = montant - 50;
			billet50++;
		}

		while(montant >= 20) {
			montant = montant - 20;
			billet20++;
		}

		while(montant >= 10) {
			montant = montant - 10;
			billet10++;
		}
	}

	printf("Nous vous donnons: %d billets de 50, %d billets de 20 et %d billets de 10\n", billet50, billet20, billet10);
}

int main(void) {
	int solde = 500;
	int stop = 0;
	int montant = 0;

	do {
		printf("Combien voulez vous retirer ?\n");
		scanf("%d", &montant);

		if (montant % 10 != 0) {
			printf("Le montant n'est pas un multiple de 10.");
			return 1;
		}

		if ((solde-montant) < 0) {
			printf("Vous n'avez pas assez sur votre compte.\n Solde restant: %d \n", montant);
			return 1;
		}

		rendu(montant);

		solde = solde - montant;
		printf("Nouveau solde: %d\n", solde);

		printf("Voulez vous arrêter ?\n1 - Oui 0 - Non\n");
		scanf("%d", &stop);
	} while(stop == 0);

	return 0;
}