#include <stdio.h>

/*prototype des sous-programmes*/
void essai_eleverCarre(int x);


//le sous-programme principal
int main(){
    int x=3;
    printf("variable x du main()=%d\n",x);
    printf("\nappel du sous-programme\n");
    essai_eleverCarre(x);
    printf("fin d'appel du sous-programme\n");
    printf("\nvariable x du main()=%d\n",x);
    return 0;
}

/*définition des sous-programmes*/
void essai_eleverCarre(int x){
    printf("\tparametre x=%d\n",x);
    x=x*x;
    printf("\tparametre x=%d\n",x);
}
