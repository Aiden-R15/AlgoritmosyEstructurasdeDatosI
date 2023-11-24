#include <stdio.h>
#include <stdbool.h>

#define N 5

void pedir_arreglo (int n_max, int a[]) {

    int i;
    i=0;

    while (i!=n_max) {
        printf ("Ingrese un valor para la posicion %d del arreglo:\n", i);
        scanf ("%d", &a[i]);
        i = i+1;

    }
    
}

int prim_iguales(int tam, int a[]) {

    int i = 0;
    int c = 1;

    while (i!=tam) {
        if (a[i]==a[i+1]) {
            c = c + 1;
        }
        else {
            i = tam - 1;
        }

        i = i + 1;
    }

    return c;

}

int main () {

    int a [N];
    pedir_arreglo (N, a);
    int c = prim_iguales (N, a);
    printf ("La cantidad de elementos iniciales iguales es: %d\n", c);

    return 0;

}