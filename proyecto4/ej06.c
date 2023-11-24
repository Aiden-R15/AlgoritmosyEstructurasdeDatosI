#include <stdio.h>

void pedir_arreglo (int n_max, int a[]) {

    int i;
    i=0;

    while (i!=n_max) {
        printf ("Ingrese un valor para la posicion %d del arreglo:\n", i);
        scanf ("%d", &a[i]);
        i = i+1;

    }
    
}

void imprimir_arreglo (int n_max, int a[]) {

    int i;
    i = 0;

    while (i!=n_max) {

        printf ("El valor numero %d del arreglo es: %d\n", i, a[i]);
        i = i+1;

    }

}

int main () {

    int n_max;
    n_max = printf ("Ingrese el tamaño que desea que tenga el arreglo:\n");
    scanf ("%d", &n_max);

    int a [n_max];
    pedir_arreglo (n_max, a);
    imprimir_arreglo (n_max, a);

    return 0;

}