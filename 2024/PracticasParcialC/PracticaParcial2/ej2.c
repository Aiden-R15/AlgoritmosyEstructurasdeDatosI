#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

struct datos {
    bool es_divisible_por_2;
    int menor_divisible_por_2;
};

struct datos hay_divisible (int tam, int a[]) {
    
    int i = 0;
    struct datos res;
    res.es_divisible_por_2 = false;
    res.menor_divisible_por_2 = INT_MAX;

    while (i<tam) {

        res.es_divisible_por_2 = res.es_divisible_por_2 || (a[i]%2==0);
        if ((a[i]%2==0)&&a[i]<res.menor_divisible_por_2) {
            res.menor_divisible_por_2 = a[i];
        }
        else {}

        i = i+1;

    }

    return res;
}

void pedir_arreglo (int n_max, int a[]) {
    
    int i = 0;

    while (i<n_max) {
        printf("Ingrese un valor para la posicion %d del arreglo: ", i);
        scanf("%d", &a[i]);
        i = i+1;
    }
}

int main () {
    int tam;
    printf ("Ingrese el tamaño del arreglo: ");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam, a);
    struct datos res = hay_divisible (tam,a);
    if (res.es_divisible_por_2) {
        printf ("Hay al menos un numero divisible por 2 y el menor es: %d\n",res.menor_divisible_por_2);
    }
    else {
        printf ("No hay un numero divisible por 2 en el arreglo\n");
    }

    return 0;

}