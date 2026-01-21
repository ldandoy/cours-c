
/*
Entrez un mot : banane
Longueur : 6
Voyelles : 3
Consonnes : 3
Commence et finit par la meme lettre : NON
*/

#include <stdio.h>
#include <string.h>

int main() {
	char mot[100];
	int voyelles = 0;
	int consonnes = 0;

	printf("Entrez un mot : ");
	scanf("%s", mot);

	int longueur = strlen(mot);
	printf("Longueur : %d\n", longueur);

	char voyelle[] = {'a', 'e', 'i', 'o', 'u', 'y'};

	for (int i = 0; i < longueur; i++) {
		int trouver = 0;

		for (int y = 0; y < 6; y++) {
			if (voyelle[y] == mot[i]) {
				trouver = 1;
				break;
			}
		}

		if (trouver == 1) {
			voyelles++;
		} else {
			consonnes++;
		}
	}

	printf("Voyelles : %d\n", voyelles);
	printf("Consonnes : %d\n", consonnes);

	if (mot[0] == mot[longueur - 1]) {
		printf("Commence et finit par la meme lettre : OUI\n");
	} else {
		printf("Commence et finit par la meme lettre : NON\n");
	}

	return 0;
}
