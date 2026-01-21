// -------------------------------------------------------------
// Point d'entree — fichier: main.c
// Lance le jeu défini dans mot.c
// -------------------------------------------------------------
#include <stdio.h>

// Prototype de la fonction fournie par mot.c
void jeu_mot_secret(void);

int main(void) {
    jeu_mot_secret();
    return 0;
}