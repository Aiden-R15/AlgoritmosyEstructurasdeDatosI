#include <stdio.h>

int main () {

    int x,y,z;

    printf ("Ingrese un valor para x: ");
    scanf ("%d", &x);
    printf ("Ingrese un valor para y: ");
    scanf ("%d", &y);
    z = x;
    x = y;
    y = z;
    printf ("Los nuevos valores son:\n x = %d\n y = %d\n",x, y);

    return 0;

}