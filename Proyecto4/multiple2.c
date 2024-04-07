#include <stdio.h>

int main () {

    int x,y,z,x2,y2;

    printf ("Ingrese un valor para x: ");
    scanf ("%d", &x);
    printf ("Ingrese un valor para y: ");
    scanf ("%d", &y);
    printf ("Ingrese un valor para z: ");
    scanf ("%d", &z);
    x2 = x;
    y2 = y;
    x = y2;
    y = x2 + y2 + z;
    z = y2 + x2;
    printf ("Los nuevos valores son:\n x = %d\n y = %d\n z = %d\n",x, y, z);

    return 0;

}