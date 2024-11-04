#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

/*Parcial del 06/11/23 tema H*/

int main () {
    int x,y,z;
    printf ("Ingrese un valor para x: ");
    scanf ("%d", &x);
    printf ("Ingrese un valor para y: ");
    scanf ("%d", &y);
    printf ("Ingrese un valor para z: ");
    scanf ("%d", &z);
    int auxX = x;
    int auxY = y;
    int auxZ = z;
    if (x>=z) {
        x = auxY+auxZ;
        y = auxX+auxZ;
        z = auxX+auxY;
    }
    else {
        x = auxY;
        y = auxZ;
        z = auxX;
    }
    printf ("El nuevo valor de x es: %d\n",x);
    printf ("El nuevo valor de y es: %d\n",y);
    printf ("El nuevo valor de z es: %d\n",z);

    return 0;
}