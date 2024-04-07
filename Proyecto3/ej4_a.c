#include <stdio.h>

int sis (int x, int y) {

    if (x>=y) {
        x = 0;
    }
    else {
        x = 2;
    }

    return x;
    
}

int main () {
    int x;
    int y;

    printf ("Ingrese un valor para x: \n");
    scanf ("%d", &x);
    printf ("Ingrese un valor para y: \n");
    scanf ("%d", &y);
    x = sis (x, y);
    printf ("Ahora los nuevos valores son: x=%d y=%d", x, y);

    return 0;

}