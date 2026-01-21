#include <stdio.h>

int main(void) {
    int step = 0;

    printf("Combien d'étage:\n");
    scanf("%d", &step);


    for (int i = 0; i<step; i++) {
        for (int j = 0; j<=i; j++) {
            putchar('*');
        }
        putchar('\n');
    }
    
    return 0;
}