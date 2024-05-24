#include <stdio.h>

int main () {
    
    int x,y,z;
    printf("Ingrese un valor de x: ");
    scanf("%d", &x);
    printf("Ingrese un valor de y: ");
    scanf("%d", &y);
    printf("Ingrese un valor de z: ");
    scanf("%d", &z);
    int auxX = x;
    int auxY = y;
    x = y;
    y = y + x;
    z = auxX + auxY;
    printf ("Los nuevos valores son:\nx = %d\ny = %d\nz = %d\n",x,y,z);

    return 0;

}