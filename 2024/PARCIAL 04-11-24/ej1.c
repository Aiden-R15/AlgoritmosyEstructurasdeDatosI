#include <stdio.h>
#include <assert.h>
#define N 4

int sum_init(int tam, int a[], int n) {

    assert (n<=tam);

    int i = 0;
    int sum = 0;

    while (i<n) {
        sum = sum+a[i];
        i = i+1;
    }

    return sum;
}

void pedir_arreglo (int tam, int a[]) {

    int i = 0;
    while (i<tam) {
        printf ("Ingrese un valor para la posicion %d del arreglo: ",i);
        scanf ("%d", &a[i]);
        i = i+1;
    }
}

int main () {

    int a[N];
    pedir_arreglo (N,a);
    int n;
    printf ("Ingrese un valor para n: ");
    scanf ("%d", &n);
    int sum = sum_init (N,a,n);
    printf ("El resultado de sumar los primeros %d elementos del arreglo es: %d\n",n,sum);

    return 0;

}

/*
Ingrese un valor para la posicion 0 del arreglo: 3
Ingrese un valor para la posicion 1 del arreglo: 6
Ingrese un valor para la posicion 2 del arreglo: 5
Ingrese un valor para la posicion 3 del arreglo: 8
Ingrese un valor para n: 3
El resultado de sumar los primeros 3 elementos del arreglo es: 14
*/

/*
Ingrese un valor para la posicion 0 del arreglo: 1
Ingrese un valor para la posicion 1 del arreglo: 6
Ingrese un valor para la posicion 2 del arreglo: 3
Ingrese un valor para la posicion 3 del arreglo: 7
Ingrese un valor para n: 4
El resultado de sumar los primeros 4 elementos del arreglo es: 17
*/

