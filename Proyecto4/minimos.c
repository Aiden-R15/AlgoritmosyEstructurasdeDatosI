#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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

int minimo_pares (int tam, int a[]) {

    int i = 0;
    int minP = INT_MAX;
    
    while (i!=tam) {
        if (a[i]<minP && a[i]%2==0) {
            minP = a[i];
        }
        else {
        }
        i = i + 1;
    }

    return minP;

}

int minimo_impares (int tam, int a[]) {

    int i = 0;
    int minI = INT_MAX;
    
    while (i!=tam) {
        if (a[i]<minI && a[i]%2!=0) {
            minI = a[i];
        }
        else {
        }
        i = i + 1;
    }

    return minI;

}

int minimo (int minP, int minI) {

    int min;
     
    if (minP<minI) {
        min = minP;
    }
    else {
        min = minI;
    }

    return min;
}

int main () {

    int tam;
    tam = printf ("Ingrese el tamaño que desea que tenga el arreglo:\n");
    scanf ("%d", &tam);

    int a [tam];
    pedir_arreglo (tam, a);
    imprimir_arreglo (tam, a);
    int minP = minimo_pares (tam, a);
    int minI = minimo_impares (tam, a);
    int min = minimo (minP, minI);
    printf ("El valor minimo del arreglo es: %d\nEl valor minimo par del arreglo es: %d\nEl valor minimo impar del arreglo es: %d\n", min, minP, minI);

    return 0;

}