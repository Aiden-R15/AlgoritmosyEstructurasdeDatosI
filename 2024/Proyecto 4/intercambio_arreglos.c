#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

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

void intercambiar(int tam, int a[], int i, int j) {
    
    assert (i<tam&&j<tam);
    int aux= a[i];
    a[i] = a[j];
    a[j] = aux;
}

int main () {

    int tam,i,j;
    printf ("Ingrese el tamaño del arreglo: ");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam, a);
    printf ("Ingrese una posicion del arreglo: ");
    scanf ("%d", &i);
    printf ("Ingrese otra posicion del arreglo: ");
    scanf ("%d", &j);
    intercambiar (tam, a, i, j);
    imprimir_arreglo (tam,a);

    return 0;

}