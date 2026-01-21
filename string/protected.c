#include <stdio.h>
#include "auth.h"

int main(void) {
	int authenticated = 0;
	char login[20];
	char password[20];

	// bouche qui demande l'authentification
	do {
		demande(login, password);

		printf("%s", login);

		authenticated = valide(login, password);
	} while(authenticated == 0);
	return 0;
}