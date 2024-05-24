#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

void pedir_arreglo(int n_max, int a[]) {

    int i = 0;
    
    while (n_max>i) {
        printf ("Ingrese el valor %d del arreglo: ", i);
        scanf ("%d", &a[i]);
        i = i+1;
    }

}

int minimo_pares (int tam, int a[]) {
    int par = INT_MAX;
    int i = 0;
    while (i<tam) {
        if (a[i]%2==0&&a[i]<par) {
            par = a[i];
        }
        else {
        }
        i = i+1;
    }

    return par;

}

int minimo_impares(int tam, int a[]) {
    int impar = INT_MAX;
    int i = 0;
    while (i<tam) {
        if (a[i]%2!=0&&a[i]<impar) {
            impar = a[i];
        }
        else {
        }
        i = i+1;
    }

    return impar;

}

int main () {

    int tam,par,impar;
    printf ("Ingrese el tamaño del arreglo: ");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam, a);
    par = minimo_pares (tam, a);
    impar = minimo_impares (tam, a);
    printf ("El minimo valor par del arreglo es: %d\nEl minimo valor impar del arreglo es: %d\n",par,impar);
    if (par>=impar) {
        printf ("El minimo valor del arreglo es: %d\n",impar);
    }
    else {
        printf ("El minimo valor del arreglo es: %d\n",par);
    }
    
    return 0;

}