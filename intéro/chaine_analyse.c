#include <stdio.h>
#include <string.h>
#include <ctype.h>

int est_voyelle(char c) {
    c = (char)tolower((char)c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

int main(void) {
    char mot[100];
    int voyelles = 0;

    printf("Mot (sans espace) : ");
    scanf("%99s", mot);

    int len = (int)strlen(mot);

    for (int i = 0; i < len; i++) {
        if (est_voyelle(mot[i])) voyelles++;
    }

    int palindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (tolower((char)mot[i]) != tolower((char)mot[len - 1 - i])) {
            palindrome = 0;
            break;
        }
    }

    printf("Longueur : %d\n", len);
    printf("Voyelles : %d\n", voyelles);
    printf("Palindrome : %s\n", palindrome ? "OUI" : "NON");

    return 0;
}
