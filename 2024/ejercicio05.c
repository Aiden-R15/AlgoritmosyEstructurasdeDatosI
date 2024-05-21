#include <stdio.h>

void pedir_arreglo(int n_max, int a[]) {

    int i = 0;
    
    while (n_max>i) {
        printf ("Ingrese el valor %d del arreglo: ", i);
        scanf ("%d", &a[i]);
        i = i+1;
    }

}

void imprimir_arreglo(int n_max, int a[]) {
    int i = 0;
    while (n_max>i) {
        printf ("El valor %d del arreglo es: %d\n", i, a[i]);
        i = i+1;
    }
}

int main () {

    int tam;
    printf ("Ingrese el tamaño del arreglo: ");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam, a);
    imprimir_arreglo (tam, a);

    return 0;

}