#include <stdio.h>

int main () {
    int i;
    
    printf ("Ingrese un valor de i:\n");
    scanf ("%d", &i);
    while (i!=0){
        i = 0;
        printf ("El nuevo valor de i es %d\n", i);
    }
    printf ("El valor final de i es %d\n", i);

    return 0;

}