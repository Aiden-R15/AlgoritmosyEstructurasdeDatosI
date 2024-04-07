#include <stdio.h>

void imprimir_hola () {

    printf ("Hola\n");

}

void imprimir_chau () {

    printf ("Chau\n");
    
}

int main () {

    int i, x;
    i = 0;

    printf ("Ingrese un numero entero:\n");
    scanf ("%d", &x);
    while (x>i){
        imprimir_hola ();
        i = i+1;
    }
    i = 0;
    while (x>i) {
        imprimir_chau ();
        i = i+1;
    }
    
    return 0;

}