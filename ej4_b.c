#include <stdio.h>

int main () {

    int x;
    int y;
    int z;
    int m;

    printf("Ingrese un valor para x\n");
    scanf("%d", &x);
    printf("Ingrese un valor para y\n");
    scanf("%d", &y);
    printf("Ingrese un valor para z\n");
    scanf("%d", &z);
    printf("Ingrese un valor para m\n");
    scanf("%d", &m);

    if (x < y){
    m = x;
    }
    else {
    m = y; 
    }
    printf ("El nuevo valor de m es %d\n" ,m);
    if (m < z){
    }
    else {
    m = z;
    }   
    printf ("El nuevo valor de m es %d\n" ,m);

    return 0;

}

/*Ingrese un valor para x
5
Ingrese un valor para y
4
Ingrese un valor para z
8
Ingrese un valor para m
0
El nuevo valor de m es 4
El nuevo valor de m es 4
----------------------------
Ingrese un valor para x
9
Ingrese un valor para y
8
Ingrese un valor para z
7
Ingrese un valor para m
6
El nuevo valor de m es 8
El nuevo valor de m es 7
*/