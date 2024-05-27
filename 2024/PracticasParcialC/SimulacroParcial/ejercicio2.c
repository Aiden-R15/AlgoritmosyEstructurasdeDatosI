#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

#define N 4

typedef struct {
    int cant_v;          
    int cant_pares;      
    int cant_imp;   
    bool hay_8;     
} datos;

datos llenar_estructura (int a[], int tam, int v) {
    datos d;
    int i = 0;
    d.cant_imp = 0;
    d.cant_pares = 0;
    d.cant_v = 0;
    d.hay_8 = false;
    while (i<tam) {
        if (a[i]%2==0) {
            d.cant_pares = d.cant_pares+1;
        }
        else {
            d.cant_imp = d.cant_imp+1;
        }
        if (a[i]==v) {
            d.cant_v = d.cant_v+1;
        }
        if (a[i]==8) {
            d.hay_8 = true;
        }
        i = i+1;
    }

    return d;

}

void pedir_arreglo(int n_max, int a[]) {

    int i = 0;
    
    while (n_max>i) {
        printf ("Ingrese el valor %d del arreglo: ", i);
        scanf ("%d", &a[i]);
        i = i+1;
    }

}

int main () {

    int a[N];
    int n;
    pedir_arreglo (N, a);
    printf ("Ingrese un valor para buscar en el arreglo: ");
    scanf ("%d", &n);
    datos d = llenar_estructura (a,N,n);
    printf ("Cantidad de valores pares: %d\nCantidad de valores impares: %d\nCantidad de veces que aparece %d: %d\n",d.cant_pares,d.cant_imp,n,d.cant_v);
    if (d.hay_8) {
        printf ("Hay al menos un 8 en el arreglo\n");
    }
    else {
        printf ("No hay ningun 8 en el arreglo\n");
    }

    return 0;

}