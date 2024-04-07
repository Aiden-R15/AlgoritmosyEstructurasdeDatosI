#include <stdio.h>

void ejercicio1 (int x) {

    x = 5;
    printf("Programa 1: El nuevo valor de x es %d\n", x);

};

void ejercicio2 (int x, int y) {

    x = x + y;
    y = y + y;
    printf("Programa 2: El nuevo valor de x es %d y el nuevo valor de y es %d\n", x, y);
};

void ejercicio3 (int x, int y) {

    y = y + y;
    x = x + y;
    printf("Programa 3: El nuevo valor de x es %d y el nuevo valor de y es %d\n", x, y);
};

int main () {
    int x;
    int y;

    printf ("Ingrese un valor de x:\n");
    scanf ("%d", &x);
    printf ("Ingrese un valor de y:\n");
    scanf ("%d", &y);
    ejercicio1 (x);
    ejercicio2 (x, y);
    ejercicio3 (x, y);

    return 0;

}

/*
programa        | usuario ingresa un σ0 | produce una salida σ
----------------|-----------------------|-------------------------
1.a ejecucion 1 |        x:=3           |         x:=5  
1.a ejecucion 2 |        x:=8           |         x:=5  
1.a ejecucion 3 |        x:=10          |         x:=5  
------------------------------------------------------------------
1.b ejecucion 1 |     x:=3  y:=4        |      x:=7  y:=8
1.b ejecucion 2 |     x:=8  y:=2        |      x:=10 y:=4
1.b ejecucion 3 |     x:=10 y:=6        |      x:=7  y:=12
------------------------------------------------------------------
1.c ejecucion 1 |     x:=3  y:=4        |      x:=11 y:=8
1.c ejecucion 2 |     x:=8  y:=2        |      x:=12 y:=4
1.c ejecucion 3 |     x:=10 y:=6        |      x:=7  y:=12
*/