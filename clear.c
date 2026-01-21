#include <stdio.h>
#include <stdlib.h>


void clear_console(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(void) {
    printf("Hello\n");
    system("pause");   // attend une touche
    clear_console();    // efface la console (Windows uniquement)
    printf("Écran nettoyé !\n");
    return 0;
}
