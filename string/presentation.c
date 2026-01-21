// ' ou "
char lettre = 'A';
char lettre[] = "ABC";

// Création d'un chaine
char mot[10] = "ECE";

// ASCII
char c = 'A';
printf("%c -> %d\n", c,c);

// Par courir une chaine
char prenom[] = "Toto";
for (int i=0; prenom[i] != '\0'; i++) {
	printf("%c", prenom[i]);
}

/*
Demander un mot à l'utilisateur
*/


// Demander et afficher
#include <stdio.h>

int main(void) {
	char prenom[100];
	printf("Entrez votre prénom:");
	scanf("%99s", prenom);

	printf("Bonjour %s !\n", prenom);

	return 0;
}

// En utilisant fgets, crée un programme qui sécurise les entrées 
// utilisateurs.

#include <stdio.h>
#define TAILLE 100

int main(void) {
	char phrase[TAILLE];

	printf("Entrez une phrase : ");
	fgets(phrase, TAILLE, stdin);

	printf("Vous avez saisi : %s", phrase);
}

// Passage en parametre
#include <stdio.h>

void afficher(char *text) {
	printf("Contenu recu: %s", text);
}

int main (void) {
	char message[] = "Bonjour ECE";
	afficher(message);
	return 0;
}

// Copy
char phrase[20] = "ECE Paris";
phrase = "ECE Lyon";

#include <string.h>

char phrase[20] = "ECE Paris";
strcpy(phrase, "ECE Lyon")

// Comparaison
int res = strcmp(a, b);

// concatenation
strcat(message, "Test");
printf("%s", message);

// Taille 
int taile = strlen(message);
printf("%d", taille)


// ------------------------------

/* Exo 1:
On demande un mot à l'utilisateur.
On affiche le nombre de lettre.
*/

/* Exo 2:
On affiche en plus le nombre voyelle
*/

/* Exo 3:
On demande le nom et le prénom et l'age
Puis on affiche <prenom> <nom> à <age>
*/

/* Exo4:
Programme à accès réduit:
Lorsqu'on démarre le programme, un login 
mot de passe est demandé.
Tant qu'il n'est pas valide (admin/admin)
 alors on redemande l'access.
*/

/* Exo5:
On cette fois on compte le nombre d'essai, et on arrête de le programme
s'il y a plus de 3 fausses tentative.
*/

/* Exo6: Le mot mystère.
On choisit un mot parmis plusieurs possible.
On demande a l'utilisateur un mot de 6 lettres. Il a 8 essai pour 
trouver.
A près chaque essaye on lui dit les lettres trouvés, mal placé et 
non trouvé
*/