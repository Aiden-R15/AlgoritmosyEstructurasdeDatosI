#include <stdio.h>
#include <stdbool.h>

int main () {

    int x, i;
    bool res;

    i = 2;
    res = true;
    printf ("Ingrese un valor para x:\n");
    scanf ("%d", &x);
    while (i<x && res){
        res = res && (x%i != 0);
        i = i+1;
        printf("El nuevo valor para x es %d y el nuevo valor para i es %d\n", x,i);
    }
    printf("El valor final de x es %d y el de i es %d\n", x, i);

    return 0;

}