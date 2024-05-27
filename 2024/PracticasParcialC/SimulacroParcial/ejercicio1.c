#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

struct info_t {
    int op_sum; // Guarda la suma
    int op_mul; // Guarda la multiplicación
    int op_div; // Guarda la división entera
    int op_dist; // Guarda el valor absoluto de la resta
};

struct info_t operar(int x, int y) {
    struct info_t res;
    int resta = x-y;
    res.op_sum = x+y;
    res.op_mul = x*y;
    res.op_div = x/y;
    if (resta>=0) {
        res.op_dist = resta;
    }
    else {
        res.op_dist = -resta;
    }

    return res;

}

int main () {
    int x,y;
    printf("Ingrese un valor entero: ");
    scanf ("%d",&x);
    assert (x>0);
    printf("Ingrese otro valor entero: ");
    scanf ("%d",&y);
    assert (y>0);
    assert (x>y);
    struct info_t res = operar (x,y);
    printf ("El resultado de la suma de valores es: %d\nLa multiplicacion de valores es: %d\nLa division de valores es: %d\nLa distancia entre los valores es: %d\n",res.op_sum,res.op_mul,res.op_div,res.op_dist);

    return 0;

}