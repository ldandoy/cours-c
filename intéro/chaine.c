#include <stdio.h>
#include <string.h>

int main(void) {
    char m1[100], m2[100];

    printf("Mot 1 (sans espace) : ");
    scanf("%99s", m1);
    printf("Mot 2 (sans espace) : ");
    scanf("%99s", m2);

    // Identiques / différents
    if (strcmp(m1, m2) == 0) {
        printf("Identiques\n");
    } else {
        printf("Differents\n");
    }

    int l1 = (int)strlen(m1);
    int l2 = (int)strlen(m2);

    // Plus long
    if (l1 > l2) printf("Mot 1 est plus long\n");
    else if (l2 > l1) printf("Mot 2 est plus long\n");
    else printf("Meme longueur\n");

    // Lettres communes à la même position
    int min = (l1 < l2) ? l1 : l2;
    int communes = 0;
    for (int i = 0; i < min; i++) {
        if (m1[i] == m2[i]) communes++;
    }
    printf("Lettres communes a la meme position : %d\n", communes);

    return 0;
}