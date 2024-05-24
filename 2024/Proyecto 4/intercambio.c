#include <stdio.h>

int pedir_entero () {

    int n;
    printf ("Ingrese un numero entero: ");
    scanf("%d", &n);

    return n;

}

int main () {
    int x,y,z,aux;
    printf ("Ingrese un valor para x: ");
    scanf ("%d", &x);
    printf ("Ingrese un valor para y: ");
    scanf ("%d", &y);
    printf ("Ingrese un valor para z: ");
    scanf ("%d", &z);

    aux = x;
    x = y;
    y = z;
    z = aux;

    printf ("Los nuevos valores son:\nx = %d\ny = %d\nz = %d\n",x,y,z);

    return 0;
}