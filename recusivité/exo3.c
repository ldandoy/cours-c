/*
La suite de Fibonacci est définie par :

F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)

Écrire une fonction récursive :

int fibonacci(int n);

qui retourne le nème de terme de la suite de Fibonacci.

Ensuite écrire un programme qui :

demande un entier n

affiche F(n)


Exemple

Entrée :

n = 6

Sortie :

Fibonacci(6) = 8

Car :

0 1 1 2 3 5 8
*/















#include <stdio.h>

int fibonacci(int n) {

    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n;

    printf("Entrez n : ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    return 0;
}