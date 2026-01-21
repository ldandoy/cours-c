#include <stdio.h>
#include <string.h>

int main(void) {
	char buffer[128];
	int age;
	printf("Ajouter un nom:");
	
	fgets(buffer, sizeof buffer, stdin);
	strtok(buffer, "\n");

	printf("Ajouter l'age:");
	scanf("%d", &age);

	printf("%s et vous avez %d", buffer, age);
	
	return 0;
}