#include <stdio.h>
#include <assert.h>

int suma_hasta (int n) {
    int i = 1;
    int x = 0;

    while (n>=i) {
        x = x + i;
        i = i + 1;
    }

    return x;

}

int pedir_entero () {

    int n;
    printf ("Ingrese un numero entero: ");
    scanf("%d", &n);
    assert (n>=0);

    return n;

}

int main () {

    int n = pedir_entero();
    int x = suma_hasta (n);
    printf ("La suma de los %d primeros enteros es: %d\n",n,x);

    return 0;

}