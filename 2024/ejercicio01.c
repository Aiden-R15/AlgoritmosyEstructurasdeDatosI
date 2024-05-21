#include <stdio.h>
#include <assert.h>

void hola_hasta(int n) {

    while (n>0) {
        printf ("Hola\n");
        n = n-1;
    }

}

int pedir_entero () {

    int n;
    printf ("Ingrese un numero entero: ");
    scanf("%d", &n);
    assert (n>0);

    return n;

}

int main () {
    
    int n = pedir_entero();
    hola_hasta (n);

    return 0;
    
}