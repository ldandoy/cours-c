// Exercice 1 (Contact : struct + saisie + affichage)
//
// On souhaite manipuler des contacts définis par :
// un nom (chaîne de caractères),
// un âge (entier).

// Définir une structure Contact contenant :
// un champ nom (30 caractères),
// un champ age.

// Écrire un programme qui :
// déclare une variable de type Contact,
// demande à l’utilisateur de saisir le nom et l’âge,
// affiche les informations du contact sous la forme : Alice a 25 ans

#include <stdio.h>
#include <string.h>

struct Contact {
    char nom[30];
    int age;
};

int main(void) {
    struct Contact c;

    printf("Nom (sans espace) : ");
    scanf("%29s", c.nom);

    printf("Age : ");
    scanf("%d", &c.age);

    printf("%s a %d ans\n", c.nom, c.age);

    return 0;
}

// Exercice 2 (Tableau de 5 étudiants : moyenne + >= moyenne)
//
// On souhaite gérer un tableau de 5 étudiants.
// Chaque étudiant est défini par :
// un nom,
// une note (entier entre 0 et 20).
//
// Déclarer un tableau de 5 structures Etudiant.
//
// À l’aide d’une boucle :
// saisir le nom et la note de chaque étudiant,
// calculer la moyenne des notes.
//
// Afficher :
// la moyenne,
// le nom des étudiants ayant une note supérieure ou égale à la moyenne.

#include <stdio.h>

#define NB 5

struct Etudiant {
    char nom[30];
    int note; // 0..20
};

int main(void) {
    struct Etudiant e[NB];
    int somme = 0;

    for (int i = 0; i < NB; i++) {
        printf("Etudiant %d - Nom (sans espace) : ", i + 1);
        scanf("%29s", e[i].nom);

        do {
            printf("Etudiant %d - Note (0..20) : ", i + 1);
            scanf("%d", &e[i].note);
        } while (e[i].note < 0 || e[i].note > 20);

        somme += e[i].note;
    }

    float moyenne = (float)somme / NB;
    printf("\nMoyenne : %.2f\n", moyenne);
    printf("Etudiants au-dessus ou egaux a la moyenne :\n");

    for (int i = 0; i < NB; i++) {
        if (e[i].note >= moyenne) {
            printf("- %s (%d)\n", e[i].nom, e[i].note);
        }
    }

    return 0;
}

// Exercice 3 (Produits : écriture dans produits.txt puis lecture/affichage)
//
// On souhaite sauvegarder des produits dans un fichier texte.
//
// Un produit est défini par :
// un nom,
// un prix (réel).
//
// Le fichier s’appelle produits.txt.
//
// Écrire un programme qui :
// ouvre le fichier en écriture,
// demande à l’utilisateur de saisir 3 produits,
// écrit chaque produit dans le fichier sous la forme :
// stylo 1.50
// cahier 2.30
//
// Écrire ensuite le code permettant :
// d’ouvrir le fichier en lecture,
// d’afficher tous les produits stockés.

#include <stdio.h>

#define NB 3

struct Produit {
    char nom[30];
    float prix;
};

int main(void) {
    struct Produit p;

    // 1) Ecriture
    FILE *f = fopen("produits.txt", "w");
    if (f == NULL) {
        printf("Erreur: impossible d'ouvrir produits.txt en ecriture.\n");
        return 1;
    }

    for (int i = 0; i < NB; i++) {
        printf("Produit %d - Nom (sans espace) : ", i + 1);
        scanf("%29s", p.nom);

        printf("Produit %d - Prix : ", i + 1);
        scanf("%f", &p.prix);

        fprintf(f, "%s %.2f\n", p.nom, p.prix);
    }

    fclose(f);

    // 2) Lecture
    f = fopen("produits.txt", "r");
    if (f == NULL) {
        printf("Erreur: impossible d'ouvrir produits.txt en lecture.\n");
        return 1;
    }

    printf("\n--- Contenu de produits.txt ---\n");
    while (fscanf(f, "%29s %f", p.nom, &p.prix) == 2) {
        printf("%s : %.2f\n", p.nom, p.prix);
    }

    fclose(f);
    return 0;
}
