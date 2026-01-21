#include <string.h>
#include <stdio.h>

int main(void) {
	char nom[20];
	char prenom[20];
	int age;

	printf("Entrez votre Nom: ");
	scanf("%19s", nom);

	printf("Entrez votre Prenom: ");
	scanf("%19s", prenom);

	printf("Entrez votre Age: ");
	scanf("%d", &age);

	printf("%s %s a %d", nom, prenom, age);

	return 0;
}