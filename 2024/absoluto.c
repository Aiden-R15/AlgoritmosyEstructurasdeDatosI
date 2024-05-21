#include <stdio.h>
#include <assert.h>

int valor_abs (int n) {

    if (n>=0) {
        return n;
    }
    else {
        return -n;
    }
}


int pedir_entero () {

    int n;
    printf ("Ingrese un numero entero: ");
    scanf("%d", &n);

    return n;

}

int main () {

    int n = pedir_entero();
    n = valor_abs (n);
    printf ("El valor absoluto es: %d\n", n);

    return 0;

}