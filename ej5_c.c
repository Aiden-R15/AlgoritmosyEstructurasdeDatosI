#include <stdio.h>

int main () {

    int x, y, i;

    printf ("Ingrese un valor positivo de x:\n");
    scanf ("%d", &x);
    printf ("Ingrese un valor positivo de y:\n");
    scanf ("%d", &y);
    i = 0;
    while (x>=y) {
        x = x - y;
        i = i + 1;
        printf ("El nuevo valor de x es %d y el nuevo valor de i es %d", x, i);
    }
    printf ("\nLos valores finales son: x=%d y=%d i=%d", x, y, i);

    return 0;

}