#include <stdio.h>

void pedir_arreglo(int n_max, int a[]) {

    int i = 0;
    
    while (n_max>i) {
        printf ("Ingrese el valor %d del arreglo: ", i);
        scanf ("%d", &a[i]);
        i = i+1;
    }

}

int sumatoria (int tam, int a[]) {

    int res = 0;
    int i = 0;
    
    while (i<tam) {

        res = res+a[i];
        i = i+1;

    }

    return res;

}

int main () {

    int tam;
    printf ("Ingrese el tamaño del arreglo: ");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam, a);
    int n = sumatoria (tam, a);
    printf ("El resultado de la sumatoria es: %d\n", n);

    return 0;

}