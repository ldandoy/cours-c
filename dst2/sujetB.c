// Exercice 1 — Structure et conditions (6 points)
//
// On souhaite manipuler des livres définis par :
// un titre (chaîne de caractères),
// un nombre de pages (entier).
//
// Définir une structure Livre contenant ces deux informations.
//
// Écrire un programme qui :
// déclare une variable de type Livre,
// demande à l’utilisateur de saisir le titre et le nombre de pages,
// affiche :
// le titre du livre,
// si le livre est court (moins de 100 pages) ou long (100 pages ou plus).
//
// Exemple
// Titre : LePetitPrince
// Pages : 96
// Le livre est court.

#include <stdio.h>

struct Livre {
    char titre[50];
    int pages;
};

int main(void) {
    struct Livre l;

    printf("Titre (sans espace) : ");
    scanf("%49s", l.titre);

    printf("Nombre de pages : ");
    scanf("%d", &l.pages);

    printf("Titre : %s\n", l.titre);
    if (l.pages < 100) {
        printf("Le livre est court.\n");
    } else {
        printf("Le livre est long.\n");
    }

    return 0;
}



// Exercice 2 — Tableau de structures et statistiques (8 points)
//
// On souhaite gérer un tableau de 4 employés.
//
// Chaque employé est défini par :
// un nom,
// un salaire (entier).
//
// Déclarer un tableau de 4 structures Employe.
//
// À l’aide d’une boucle :
// saisir les informations de chaque employé,
// calculer le salaire moyen.
//
// Afficher :
// le salaire moyen,
// le nom des employés dont le salaire est strictement supérieur à la moyenne.

#include <stdio.h>

#define NB 4

struct Employe {
    char nom[30];
    int salaire;
};

int main(void) {
    struct Employe t[NB];
    int somme = 0;

    for (int i = 0; i < NB; i++) {
        printf("Employe %d - Nom (sans espace) : ", i + 1);
        scanf("%29s", t[i].nom);

        do {
            printf("Employe %d - Salaire (>= 0) : ", i + 1);
            scanf("%d", &t[i].salaire);
        } while (t[i].salaire < 0);

        somme += t[i].salaire;
    }

    float moyenne = (float)somme / NB;
    printf("\nSalaire moyen : %.2f\n", moyenne);
    printf("Employes strictement au-dessus de la moyenne :\n");

    for (int i = 0; i < NB; i++) {
        if (t[i].salaire > moyenne) {
            printf("- %s (%d)\n", t[i].nom, t[i].salaire);
        }
    }

    return 0;
}


// Exercice 3 — Fichier texte et tableau (6 points)
//
// On souhaite enregistrer des scores de jeu dans un fichier texte scores.txt.
//
// Un score est défini par :
// un pseudo,
// un score (entier).
//
// Écrire un programme qui :
// ouvre le fichier scores.txt en écriture,
// demande à l’utilisateur de saisir 5 scores,
// écrit chaque score dans le fichier sous la forme :
// Alice 120
// Bob 95
//
// Écrire ensuite le code permettant :
// d’ouvrir le fichier en lecture,
// d’afficher tous les scores,
// d’indiquer le meilleur score.

#include <stdio.h>

#define NB 5

struct Score {
    char pseudo[30];
    int score;
};

int main(void) {
    struct Score s;

    // 1) Ecriture
    FILE *f = fopen("scores.txt", "w");
    if (f == NULL) {
        printf("Erreur: impossible d'ouvrir scores.txt en ecriture.\n");
        return 1;
    }

    for (int i = 0; i < NB; i++) {
        printf("Score %d - Pseudo (sans espace) : ", i + 1);
        scanf("%29s", s.pseudo);

        printf("Score %d - Valeur : ", i + 1);
        scanf("%d", &s.score);

        fprintf(f, "%s %d\n", s.pseudo, s.score);
    }

    fclose(f);

    // 2) Lecture + meilleur score
    f = fopen("scores.txt", "r");
    if (f == NULL) {
        printf("Erreur: impossible d'ouvrir scores.txt en lecture.\n");
        return 1;
    }

    printf("\n--- Scores ---\n");
    int meilleur = 0;
    char meilleurPseudo[30] = "";

    int premier = 1;
    while (fscanf(f, "%29s %d", s.pseudo, &s.score) == 2) {
        printf("%s : %d\n", s.pseudo, s.score);

        if (premier || s.score > meilleur) {
            meilleur = s.score;
            // copie manuelle (sans strcpy pour rester “bases”)
            int i = 0;
            while (s.pseudo[i] != '\0' && i < 29) {
                meilleurPseudo[i] = s.pseudo[i];
                i++;
            }
            meilleurPseudo[i] = '\0';
            premier = 0;
        }
    }

    fclose(f);

    if (!premier) {
        printf("\nMeilleur score : %s avec %d\n", meilleurPseudo, meilleur);
    } else {
        printf("\nAucun score lu.\n");
    }

    return 0;
}
