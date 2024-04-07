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
    int x = 0;
    int y = 0;
    int z = 0;
    /*Ingreso de valores a las variables*/
    printf("Ingrese el valor de x:\n");
    scanf("%d", &x);
    printf("Ingrese el valor de y:\n");
    scanf("%d", &y);
    printf("Ingrese el valor de z:\n");
    scanf("%d", &z);
    printf("el resultado de %d + %d +1 es: %d \n",x,y,x+y+1);
    printf("el resultado de %d * %d + %d * 45 - 15 * %d es: %d\n",z,z,y,x,z*z+y*45-15*x);
    printf("el resultado de %d - 2 == ( %d * 3 + 1)/5 es: %s\n",y,x,comprobacion((z*z + y*45 - 45*x)));
    printf("el resultado de %d / 2 * %d es: %d\n",y,x,y/2*x);
    printf("el resultado de %d < %d * %d es: %s\n",y,x,z,comprobacion((y<x*z)));

    return 0;
}

/*
Ingrese el valor de x:
7
Ingrese el valor de y:
3
Ingrese el valor de z:
5
el resultado de 7 + 3 +1 es: 11 
el resultado de 5 * 5 + 3 * 45 - 15 * 7 es: 55
el resultado de 3 - 2 == ( 7 * 3 + 1)/5 es: False
el resultado de 3 / 2 * 7 es: 7
el resultado de 3 < 7 * 5 es: True
    
Ingrese el valor de x:
1
Ingrese el valor de y:
10
Ingrese el valor de z:
8
el resultado de 1 + 10 +1 es: 12 
el resultado de 8 * 8 + 10 * 45 - 15 * 1 es: 499
el resultado de 10 - 2 == ( 1 * 3 + 1)/5 es: False
el resultado de 10 / 2 * 1 es: 5
el resultado de 10 < 1 * 8 es: False

en la última expresión el resultado es un booleano
*/