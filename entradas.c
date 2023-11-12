#include <stdio.h>

char pedir_nombre () {

    char name;

    printf ("Ingrese un nombre para la variable:\n");
    scanf ("%c", &name);

    return name;

}

int pedir_entero (char name) {

    int x;

    printf ("Ingrese un valor entero para %c:\n", name);
    scanf ("%d", &x);

    return x;

}

void imprimir_entero (char name,int x) {

    printf ("El valor de %c que ingreso es: %d\n", name, x);

}

int main () {
    
    int x;
    char name;

    name = pedir_nombre();
    x = pedir_entero(name);
    imprimir_entero(name, x);

    return 0;

}