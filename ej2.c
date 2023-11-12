#include <stdio.h>
#include <stdbool.h>

char * comprobacion(int expresion){
    if ((expresion) == 1){
        return "True";
    }
    return "False";
}
int main()
{
    /* Inicializacion de Variables*/
    int x, y, z, b, w;
    
    printf("Ingrese el valor de x:\n");
    scanf("%d", &x);
    printf("Ingrese el valor de y:\n");
    scanf("%d", &y);
    printf("Ingrese el valor de z:\n");
    scanf("%d", &z);
    printf("Ingrese el valor de b:\n");
    scanf("%d", &b);
    printf("Ingrese el valor de w:\n");
    scanf("%d", &w);

    /*Expresiones Solicictadas*/
    printf("Resultado de %d (Modulo) 4 == 0 es %s\n",x,comprobacion((x%4==0)));
    printf("Resultado de %d + %d == 0 && %d - %d == (-1) * %d es : %s\n",x,y,y,x,z,comprobacion((x+y == 0 && y -x == (-1) * z)));
    printf("Resultado de not %d && %d es: %s\n",b,w,comprobacion((!b && w)));

    /*Ingrese el valor de x:
    4
    Ingrese el valor de y:
    -4
    Ingrese el valor de z:
    8
    Ingrese el valor de b:
    1
    Ingrese el valor de w:
    0
    Resultado de 4 (Modulo) 4 == 0 es True
    Resultado de 4 + -4 == 0 && -4 - 4 == (-1) * 8 es : True
    Resultado de not 1 && 0 es: False
    */

    return 0;
}
