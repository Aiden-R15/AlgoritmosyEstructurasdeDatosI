#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

int main () {

    int x,y,z,auxx,auxy;
    printf ("Ingrese un valor de x: ");
    scanf ("%d", &x);
    printf ("Ingrese un valor de y: ");
    scanf ("%d", &y);
    printf ("Ingrese un valor de z: ");
    scanf ("%d", &z);
    auxx = x;
    auxy = y;
    x = auxy;
    y = auxx+auxy*z;
    z = auxx*(1+auxy*auxy);

    printf ("El nuevo valor de x es: %d\n", x);
    printf ("El nuevo valor de y es: %d\n", y);
    printf ("El nuevo valor de z es: %d\n", z);

    return 0;

}