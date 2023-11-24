#include <stdio.h>
#include <assert.h>

void hola_hasta(int n){
    while (n>0)
    {
        n = (n-1);
        printf ("Hola\n");
        
    }
}

int main (){
    int x;
    printf ("Ingrese un valor:\n");
    scanf ("%d", &x);
    assert (x>=0);
    hola_hasta (x);
    return 0;
}