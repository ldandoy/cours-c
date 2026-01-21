// -------------------------------------------------------------
// Jeu "Devine le mot secret" — fichier: mot.c
// Contient la logique du jeu (sélection du mot, saisie lettres,
// mise à jour du masque, gestion des essais, menu).
// -------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

// ===================== Constantes & utilitaires ======================
#define MAX_TENTATIVES 8
#define MAX_LONGUEUR   64

// Petit dictionnaire (ASCII pour éviter les soucis d'encodage)
static const char *DICTIONNAIRE[] = {
    "ordinateur", "programmation", "developpeur", "algorithme",
    "pointeur", "variable", "fonction", "tableau",
    "compilateur", "memoire"
};
static const int NB_MOTS = (int)(sizeof(DICTIONNAIRE) / sizeof(DICTIONNAIRE[0]));

// -------------------------------------------------------------
// Sous-programme : choisir_mot_aleatoire
// Rôle : choisir un mot au hasard depuis DICTIONNAIRE
// Entrées  → aucune
// Sortie   → pointeur vers une chaîne constante (mot choisi)
// -------------------------------------------------------------
static const char* choisir_mot_aleatoire(void) {
    int idx = rand() % NB_MOTS;
    return DICTIONNAIRE[idx];
}

// -------------------------------------------------------------
// Sous-programme : initialiser_masque
// Rôle : créer le masque initial (remplace les lettres par '_')
//         et garde tels quels les caractères non alphabétiques.
// Entrées  → mot (const char*), masque (char* de taille suffisante)
// Sortie   → aucune (masque rempli)
// -------------------------------------------------------------
static void initialiser_masque(const char *mot, char masque[]) {
    size_t n = strlen(mot);
    for (size_t i = 0; i < n; i++) {
        if (isalpha((unsigned char)mot[i])) masque[i] = '_';
        else masque[i] = mot[i]; // au cas où il y aurait tiret/espace
    }
    masque[n] = '\0';
}

// -------------------------------------------------------------
// Sous-programme : afficher_masque
// Rôle : afficher le masque avec des espaces entre les lettres
// Entrées  → masque (const char*)
// Sortie   → aucune (affiche)
// -------------------------------------------------------------
static void afficher_masque(const char *masque) {
    for (size_t i = 0; masque[i] != '\0'; i++) {
        printf("%c ", masque[i]);
    }
    printf("\n");
}

// -------------------------------------------------------------
// Sous-programme : lettre_deja_proposee
// Rôle : vérifier si une lettre a déjà été jouée
// Entrées  → tableau des lettres déjà jouées, nombre stocké, lettre testée
// Sortie   → true si déjà présente, false sinon
// -------------------------------------------------------------
static bool lettre_deja_proposee(const char deja[], int nb, char c) {
    for (int i = 0; i < nb; i++) {
        if (deja[i] == c) return true;
    }
    return false;
}

// -------------------------------------------------------------
// Sous-programme : maj_masque
// Rôle : révéler la lettre c dans le masque si elle est dans mot
// Entrées  → mot source, masque modifiable, lettre c
// Sortie   → nombre de nouvelles lettres révélées (0 si aucune)
// -------------------------------------------------------------
static int maj_masque(const char *mot, char masque[], char c) {
    int reveles = 0;
    for (size_t i = 0; mot[i] != '\0'; i++) {
        // Comparaison en minuscule pour robustesse
        char m = (char)tolower((unsigned char)mot[i]);
        if (isalpha((unsigned char)m) && m == c && masque[i] == '_') {
            masque[i] = mot[i]; // on garde la casse du mot (ici tout en minuscule)
            reveles++;
        }
    }
    return reveles;
}

// -------------------------------------------------------------
// Sous-programme : a_gagne
// Rôle : déterminer si le mot est entièrement découvert
// Entrées  → masque
// Sortie   → true si aucune '_' restante
// -------------------------------------------------------------
static bool a_gagne(const char *masque) {
    for (size_t i = 0; masque[i] != '\0'; i++) {
        if (masque[i] == '_') return false;
    }
    return true;
}

// -------------------------------------------------------------
// Sous-programme : lire_lettre
// Rôle : lire une lettre [a..z] de façon robuste (re-propose sinon)
// Entrées  → aucune
// Sortie   → la lettre saisie en minuscule
// -------------------------------------------------------------
static char lire_lettre(void) {
    char buffer[128];
    while (1) {
        printf("Proposez une lettre : ");
        if (!fgets(buffer, sizeof buffer, stdin)) {
            clearerr(stdin);
            continue;
        }
        // prendre le premier caractère alphabétique
        for (size_t i = 0; buffer[i] != '\0'; i++) {
            if (isalpha((unsigned char)buffer[i])) {
                return (char)tolower((unsigned char)buffer[i]);
            }
        }
        printf("Entree invalide (lettre requise).\n");
    }
}

// -------------------------------------------------------------
// Sous-programme : jouer_une_partie
// Rôle : lance une partie complète (sélection mot, boucle coups)
// Entrées  → aucune
// Sortie   → aucune
// -------------------------------------------------------------
static void jouer_une_partie(void) {
    const char *mot = choisir_mot_aleatoire();

    char masque[MAX_LONGUEUR];
    if (strlen(mot) >= MAX_LONGUEUR) {
        printf("Mot trop long pour le buffer.\n");
        return;
    }
    initialiser_masque(mot, masque);

    char deja[26 + 26] = {0}; // stockage des lettres déjà proposées
    int nb_deja = 0;
    int erreurs = 0;

    printf("\n=== Nouvelle partie ===\n");
    printf("Le mot comporte %zu lettres.\n", strlen(mot));

    while (erreurs < MAX_TENTATIVES && !a_gagne(masque)) {
        printf("\nMot : "); afficher_masque(masque);
        printf("Erreurs : %d / %d\n", erreurs, MAX_TENTATIVES);
        if (nb_deja > 0) {
            printf("Deja proposees : ");
            for (int i = 0; i < nb_deja; i++) printf("%c ", deja[i]);
            printf("\n");
        }

        char c = lire_lettre();
        if (lettre_deja_proposee(deja, nb_deja, c)) {
            printf("Vous avez deja propose '%c'.\n", c);
            continue;
        }

        deja[nb_deja++] = c;
        int r = maj_masque(mot, masque, c);
        if (r == 0) {
            printf("Raté ! La lettre '%c' n'est pas dans le mot.\n", c);
            erreurs++;
        } else {
            printf("Bien joue ! '%c' revele %d lettre%s.\n", c, r, (r > 1 ? "s" : ""));
        }
    }

    if (a_gagne(masque)) {
        printf("\nBravo ! Vous avez trouve : %s\n", mot);
    } else {
        printf("\nPerdu... Le mot etait : %s\n", mot);
    }
}

// -------------------------------------------------------------
// Sous-programme : afficher_menu
// Rôle : affiche le menu principal et lit le choix utilisateur
// Entrées  → aucune
// Sortie   → choix (int)
// -------------------------------------------------------------
static int afficher_menu(void) {
    int choix = 0;
    printf("\n=== DEVINE LE MOT SECRET ===\n");
    printf("1 - Jouer une partie\n");
    printf("2 - Quitter\n");
    printf("Votre choix : ");
    if (scanf("%d", &choix) != 1) {
        // nettoyer stdin si saisie invalide
        int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
        return -1;
    }
    int ch; while ((ch = getchar()) != '\n' && ch != EOF) {} // vider la ligne
    return choix;
}

// -------------------------------------------------------------
// Fonction exportée : jeu_mot_secret
// Rôle : boucle de jeu (menu + actions). A appeler depuis main.c
// Entrées  → aucune
// Sortie   → aucune
// -------------------------------------------------------------
void jeu_mot_secret(void) {
    srand((unsigned)time(NULL)); // init RNG une fois

    int choix;
    do {
        choix = afficher_menu();
        switch (choix) {
            case 1:
                jouer_une_partie();
                break;
            case 2:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 2);
}