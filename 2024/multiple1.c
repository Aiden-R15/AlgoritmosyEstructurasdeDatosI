#include <stdio.h>

int main () {
    
    int x,y;
    printf ("Ingrese un valor para x: ");
    scanf ("%d", &x);
    printf ("Ingrese un valor para y: ");
    scanf ("%d", &y);
    int aux = x;
    x = x + 1;
    y = y + aux;
    printf ("Los nuevos valores son:\nx = %d\ny = %d\n",x,y);

    return 0;

}