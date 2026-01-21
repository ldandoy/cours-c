#include <stdio.h>
#include <stdbool.h>

// Prix en centimes
#define PRIX_THE      60
#define PRIX_CAFE     40
#define PRIX_CHOCOLAT 70
#define NB_PIECES (sizeof(PIECES) / sizeof(PIECES[0]))

// Pièces acceptées (en centimes) : 5, 10, 20, 50, 1€ (100), 2€ (200)
const int PIECES[] = {200, 100, 50, 20, 10, 5};

void vider_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { /* vide */ }
}

int lire_entier(const char *invite) {
    int v; 
    int ok;
    do {
        printf("%s", invite);
        ok = scanf("%d", &v);
        vider_buffer();
        if (ok != 1) printf("Entree invalide. Reessayez.\n");
    } while (ok != 1);
    return v;
}

// ------------------------------------------------------------
// Menu & prix
// ------------------------------------------------------------
void afficher_menu(void) {
    printf("\n=== Distributeur de boissons chaudes ===\n");
    printf("1) The (60 cts)\n");
    printf("2) Cafe (40 cts)\n");
    printf("3) Chocolat chaud (70 cts)\n");
}

int prix_boisson(int choix) {
    switch (choix) {
        case 1: return PRIX_THE;
        case 2: return PRIX_CAFE;
        case 3: return PRIX_CHOCOLAT;
        default: return -1;
    }
}

bool est_piece_valide(int centimes) {
    for (int i = 0; i < NB_PIECES; i++) {
        if (centimes == PIECES[i]) return true;
    }
    return false;
}

int saisir_piece(void) {
    int p;
    printf("Inserer une piece (5,10,20,50,100,200 cts) : ");
    if (scanf("%d", &p) != 1) {
        vider_buffer();
        return -1;
    }
    vider_buffer();
    return p;
}

void rendre_monnaie(int change, int rendu[]) {
    for (int i = 0; i < NB_PIECES; i++) {
        rendu[i] = change / PIECES[i];
        change %= PIECES[i];
    }
}

void afficher_rendu(const int rendu[]) {
    int total_pieces = 0;
    printf("\nRendu de monnaie :\n");
    for (int i = 0; i < NB_PIECES; i++) {
        if (rendu[i] > 0) {
            if (PIECES[i] >= 100)
                printf("  %dx %d euro%s\n", rendu[i], PIECES[i]/100, (rendu[i] > 1 ? "s" : ""));
            else
                printf("  %dx %d centime%s\n", rendu[i], PIECES[i], (rendu[i] > 1 ? "s" : ""));
            total_pieces += rendu[i];
        }
    }
    if (total_pieces == 0) {
        printf("  Aucune piece a rendre.\n");
    }
}

int main(void) {
    afficher_menu();
    int choix = lire_entier("Votre choix (1-3) : ");
    int prix = prix_boisson(choix);

    if (prix < 0) {
        printf("Choix invalide. Fin du programme.\n");
        return 1;
    }

    int insere = 0;
    printf("\nPrix a payer : %d centimes.\n", prix);
    printf("(Pieces acceptees : 5,10,20,50,100,200 centimes)\n");

    while (insere < prix) {
        int p = saisir_piece();
        if (!est_piece_valide(p)) {
            printf("Piece refusee. Veuillez inserer une piece valide.\n");
            continue;
        }
        insere += p;
        printf("Total insere : %d cts (reste %d cts)\n", insere, (insere < prix ? prix - insere : 0));
    }

    int change = insere - prix;
    if (change > 0) {
        int rendu[NB_PIECES] =   {0};
        rendre_monnaie(change, rendu);
        afficher_rendu(rendu);
    }

    switch (choix) {
        case 1: printf("\nVoici votre the. Merci !\n"); break;
        case 2: printf("\nVoici votre cafe. Merci !\n"); break;
        case 3: printf("\nVoici votre chocolat chaud. Merci !\n"); break;
    }

    return 0;
}