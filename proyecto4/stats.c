#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct datos_t {
    float maximo;
    float minimo;
    float promedio;
};

struct datos_t stats(int tam, float a[]) {

    int i = 0;
    struct datos_t res;
    res.maximo = INT_MIN;
    res.minimo = INT_MAX;
    res.promedio = 0;

    while (i!=tam) {
        if (res.minimo>a[i]) {
            res.minimo = a[i];
        }
        else {}
        if (res.maximo<a[i]) {
            res.maximo = a [i];
        }
        else {}
        res.promedio = res.promedio + a[i];
        i = i+1;
    }
    
    res.promedio = res.promedio/2;

    return res;

}

void pedir_arreglo (int n_max, float a[]) {

    int i;
    i=0;

    while (i!=n_max) {
        printf ("Ingrese un valor para la posicion %d del arreglo:\n", i);
        scanf ("%f", &a[i]);
        i = i+1;

    }
    
}

int main () {

    int tam;
    struct datos_t res;

    tam = printf ("Ingrese el tamaño que desea que tenga el arreglo:\n");
    scanf ("%d", &tam);
    float a[tam];
    pedir_arreglo (tam, a);
    res = stats (tam, a);
    printf ("El valor maximo del arreglo es: %f\nEl valor minimo del arreglo es: %f\nEl valor promedio del arreglo es: %f\n", res.maximo, res.minimo, res.promedio);

    return 0;

}