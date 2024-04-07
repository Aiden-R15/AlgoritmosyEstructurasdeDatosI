#include <stdio.h>
#include <stdbool.h>

bool es_primo (int n) {
    
    int i = 2;

    if (n <= 1) {
        return false;
    }

    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i = i+1;
    }

    return true;

}

int nesimoPrimo(int n) {

    int i = 0;
    int num = 2;

    while (i<n) {
        if (es_primo(num)) {
            i = i+1;
        }
        num = num+1;
    }

    return n-1; 
}

int main () {

    int n;

    printf ("Ingrese un valor:\n");
    scanf("%d", &n);
    while (n<=0) {
        printf ("El valor ingresado tiene que ser positivo, intentelo nuevamente:\n");
        scanf ("%d", &n);
    }
    int p = nesimoPrimo (n);
    printf ("El primo numero %d es: %d\n", n, p);
    return 0;
}