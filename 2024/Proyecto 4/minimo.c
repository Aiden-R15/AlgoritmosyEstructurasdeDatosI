#include <stdio.h>
#include <assert.h>

int minimo (int x,int y) {

    if (x>=y) {
        return y;
    }
    else {
        return x;
    }
}

int main () {
    int x,y;
    printf ("Ingrese un valor para x: ");
    scanf ("%d", &x);
    printf ("Ingrese un valor para y: ");
    scanf ("%d", &y);
    int n = minimo (x, y);
    printf ("El valor minimo es: %d\n", n);

    return 0;
    
}