#include <stdio.h>

int main(void) {
    int t[10];
    int somme = 0;
    int max;
    int neg = 0;

    printf("Saisir 10 entiers :\n");
    for (int i = 0; i < 10; i++) {
        printf("t[%d] = ", i);
        scanf("%d", &t[i]);
        somme += t[i];
        if (t[i] < 0) neg++;
        if (i == 0 || t[i] > max) max = t[i];
    }

    printf("\nSomme = %d\n", somme);
    printf("Maximum = %d\n", max);
    printf("Valeurs negatives = %d\n", neg);

    return 0;
}
