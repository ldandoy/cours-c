#include <stdio.h>
#include <stdbool.h>

// Fonction qui vérifie si un nombre est pair
bool est_pair(int n) {
    return (n % 2 == 0);
}

int main(void) {
    int nombre;

    printf("Entrez un nombre : ");
    if (scanf("%d", &nombre) != 1) {
        printf("Entrée invalide.\n");
        return 1;
    }

    if (est_pair(nombre)) {
        printf("%d est pair.\n", nombre);
    } else {
        printf("%d est impair.\n", nombre);
    }

    return 0;
}