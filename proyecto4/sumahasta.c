#include <stdio.h>
#include <assert.h>

int suma_hasta (int n) {

    int i, x;
    x = 0;
    i = 1;

    while (i <= n) {
        x = x + i;
        i = i + 1;
    }

    return x;

}

int main () {

    int n, x;
    
    printf ("Ingrese un valor:\n");
    scanf ("%d", &n);
    assert (n>0);
    x = suma_hasta (n);
    printf ("El resultado de la sumatoria es: %d\n", x);

    return 0;
}