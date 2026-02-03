#include <stdlib.h>
#include <stdio.h>

int main()
{
	int *p = malloc(2 * sizeof(int));

	if (p == NULL) {
	    printf("Erreur allocation\n");
	    return 1;
	}

	int *a = &p[0];
	int *b = &p[1];

	printf("Entrez un entier : ");
    scanf("%d", a);

    printf("Entrez un entier : ");
    scanf("%d", b);
 	

 	// Affichage
    printf("Valeur saisie : %d, %d\n", *a, *b);

    // Liberation de la memoire
    free(p);
    p = NULL;

 	return 0;
}