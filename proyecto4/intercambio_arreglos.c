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

void intercambiar (int tam, int a[], int i, int j) {

    int aux;

    if (i!=tam || j!=tam) {
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
    }
    else{   
    }
    
}

int main () {

    int tam, i, j;
    tam = printf ("Ingrese el tamaño que desea que tenga el arreglo:\n");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam, a);
    printf ("Los valores iniciales del arreglo son:\n");
    imprimir_arreglo (tam, a);
    printf ("Ingrese los dos variables que desea intercambiar:\n");
    scanf ("%d", &i);
    scanf ("%d", &j);
    intercambiar (tam, a, i, j);
    printf ("Los nuevos valores del arreglo son:\n");
    imprimir_arreglo (tam, a);

    return 0;


}