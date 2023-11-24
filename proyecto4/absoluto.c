#include <stdio.h>

int absoluto (int x){
    if (x<0){
        x = x*(-1);
    }
    else{
        x = x; 
    }
    return x;
};

int main (){
    int x;
    printf ("Ingrese un valor para x:\n");
    scanf ("%d", &x);
    x=absoluto (x);
    printf ("El nuevo valor de x es: %d\n", x);
    return 0;
}