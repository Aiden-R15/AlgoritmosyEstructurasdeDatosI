#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4

struct datos {
    bool es_divisible_por_2;
    int menor_divisible_por_2;
};

struct datos hay_divisible (int tam, int a[]){
    int i = 0;
    struct datos res;
    res.es_divisible_por_2 = false;
    res.menor_divisible_por_2 = INT_MAX;
    while (i<tam) {
        if (a[i]%2==0) {
            res.es_divisible_por_2 = true;
            if (a[i]<res.menor_divisible_por_2) {
                res.menor_divisible_por_2 = a[i];
            }
        }
        else {}
        i = i+1;
    }

    return res;

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
    struct datos res;
    pedir_arreglo (N, a);
    res = hay_divisible (N, a);
    if (res.es_divisible_por_2) {
        printf ("Hay un/os valor/es divisibles por 2 en el arreglo y el menor es: %d\n", res.menor_divisible_por_2);
    }
    else {
        printf ("El arreglo no tiene elementos divisibles por 2\n");
    }
    return 0;

}