#include <stdio.h>
#include <assert.h>

int pedir_entero (char n) {

    int x;

    printf ("Ingrese un valor entero para %c: ",n);
    scanf ("%d", &x);

    return x;

}


void imprimir_entero (char name,int x) {

    printf ("El valor de %c es: %d\n", name, x);

}



int main () {

    int x,y,z,aux1,aux2,aux3;
    x = pedir_entero ('x');
    y = pedir_entero ('y');
    z = pedir_entero ('z');
    assert (x>0&&z>0);
    if (x>=z) {
        aux1 = x;
        aux2 = y;
        aux3 = z;
        x = aux2+z;
        y = aux1+z;
        z = aux1+aux2;
        assert (aux1>=aux3&&(x==aux2+aux3&&y==aux1+aux3&&z==aux1+aux2));
    }
    else {
        aux1 = x;
        x = y;
        y = z;
        z = aux1;
    }
    imprimir_entero ('x',x);
    imprimir_entero ('y',y);
    imprimir_entero ('z',z);

    return 0;

}