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

int sumatoria (int tam, int a[]) {

    int i,res;
    i = 0;
    res = 0;

    while (i!=tam) {
        res = res+a[i];
        i=i+1;
    }

    return res;

}

int main () {

    int tam,res;

    tam = printf ("Ingrese el tamaño que desea que tenga el arreglo:\n");
    scanf ("%d", &tam);
    int a [tam];
    pedir_arreglo (tam, a);
    imprimir_arreglo (tam, a);
    res = sumatoria (tam, a);
    printf ("La suma de valores del arreglo es igual a: %d\n", res);

    return 0;

}