#include <stdio.h>
#include <assert.h>

struct div_t {
int cociente;
int resto;
};


struct div_t division (int x, int y) {
    
    struct div_t res;
    res.cociente = x/y;
    res.resto = x%y;

    return res;

}

int pedir_entero () {

    int n;
    printf ("Ingrese un numero entero: ");
    scanf("%d", &n);

    return n;

}

int main () {

    int x,y;
    struct div_t res;

    x = pedir_entero ();
    assert (x>=0);
    y = pedir_entero ();
    assert (y>0);
    res = division (x,y);
    printf ("El cociente de la division es: %d\nEl resto de la division es: %d\n", res.cociente, res.resto);

    return 0;
    
}