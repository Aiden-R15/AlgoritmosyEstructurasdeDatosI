#include <stdio.h>

int main () {
    int i;
    
    printf ("Ingrese un valor positivo de i:\n");
    scanf ("%d", &i);
    while (i!=0){
        i = i - 1;
        printf ("El nuevo valor de i es %d\n", i);
    }
    printf ("El valor final de i es %d\n", i);

    return 0;

}