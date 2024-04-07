#include <stdio.h>

int main (){
    int x;
    int y;
    printf ("Ingrese un valor para x:\n");
    scanf ("%d", &x);
    printf ("Ingrese un valor para y:\n");
    scanf ("%d", &y);
    if (x<y){
        printf ("El valor minimo es %d\n", x);
    }
    else {
        printf ("El valor minimo es %d\n", y);
    }
    return 0;
}