/*

Une année est bissextile si :
Elle est divisible par 4,
Sauf si elle est divisible par 100,
Mais si elle est divisible par 400, elle est quand même bissextile.

Exemple :
2000 → bissextile     ✅ (divisible par 400)
1900 → pas bissextile ❌ (divisible par 100 mais pas par 400)
2024 → bissextile     ✅ (divisible par 4 et pas par 100)

*/

#include <stdio.h>

int main(void) {
    int annee;

    printf("Entrez une annee : ");
    if (scanf("%d", &annee) != 1) {
        printf("Entree invalide.\n");
        return 1;
    }

    if ((annee % 400 == 0) || (annee % 4 == 0 && annee % 100 != 0)) {
        printf("L'annee %d est bissextile.\n", annee);
    } else {
        printf("L'annee %d n'est pas bissextile.\n", annee);
    }

    return 0;
}
