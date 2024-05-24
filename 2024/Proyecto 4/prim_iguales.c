#include <stdio.h>

int prim_iguales (int tam, int a[]) {

    int res = 1;
    int i = 0;

    while (i+1<tam) {   
        if (a[i]==a[i+1]) {
            res = res+1;
        }
        else {
            return res;
        }
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

    int tam;
    printf ("Ingrese el tamaño del arreglo: ");
    scanf ("%d", &tam);
    int a[tam];
    pedir_arreglo (tam, a);
    int res = prim_iguales (tam, a);
    printf ("La cantidad de elementos iniciales del arreglo iguales son: %d\n", res);

    return 0;

}