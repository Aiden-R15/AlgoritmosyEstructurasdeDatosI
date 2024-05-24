
#include <stdio.h>
#include <limits.h>

struct datos_t {
float maximo;
float minimo;
float promedio;
};

struct datos_t stats (int tam, float a[]) {

    int i = 0;
    struct datos_t stats;
    stats.maximo = INT_MIN;
    stats.minimo = INT_MAX;

    while (i<tam) {
        if (stats.minimo>a[i]) {
            stats.minimo = a[i];
        }
        else {}
        if (stats.maximo<a[i]) {
            stats.maximo = a[i];
        }
        else {}
        stats.promedio = stats.promedio+a[i];
        i = i+1;
    }

    stats.promedio = stats.promedio/tam;

    return stats;

}

void pedir_arreglo(int n_max, float a[]) {

    int i = 0;
    
    while (n_max>i) {
        printf ("Ingrese el valor %d del arreglo: ", i);
        scanf ("%f", &a[i]);
        i = i+1;
    }

}

int main () {

    int tam;
    struct datos_t res;

    tam = printf ("Ingrese el tamaño que desea que tenga el arreglo: ");
    scanf ("%d", &tam);
    float a[tam];
    pedir_arreglo (tam, a);
    res = stats (tam, a);
    printf ("El valor maximo del arreglo es: %f\nEl valor minimo del arreglo es: %f\nEl valor promedio del arreglo es: %f\n", res.maximo, res.minimo, res.promedio);

    return 0;

}