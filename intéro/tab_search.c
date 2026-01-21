#include <stdio.h>

int main(void) {
    int t[8];
    int val;
    int occ = 0;

    printf("Saisir 8 entiers :\n");
    for (int i = 0; i < 8; i++) {
        printf("t[%d] = ", i);
        scanf("%d", &t[i]);
    } 

    printf("Valeur a rechercher : ");
    scanf("%d", &val);

    for (int i = 0; i < 8; i++) {
        if (t[i] == val) occ++;
    }

    if (occ > 0) {
        printf("La valeur %d est presente (%d occurrence%s).\n",
               val, occ, (occ > 1 ? "s" : ""));
    } else {
        printf("La valeur %d n'est pas presente.\n", val);
    }

    return 0;
}
