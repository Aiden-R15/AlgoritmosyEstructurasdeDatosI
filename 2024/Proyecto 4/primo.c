#include <stdio.h>
#include <stdbool.h>

bool es_primo (int n) {

    int i = 2;

    if (n<=1) {
        return false;
    }
    while ((i*i)<=n) {
        if(n%i==0) {
            return false;
        }
        i = i+1;
    }

    return true;

}

int nesimo_primo (int N) {

    int i = 0;
    int num = 2;

    while (i<N) {
        if (es_primo(num)) {
            i = i+1;
        }
        num = num+1;
    }

    return num-1; 
}

int pedir_entero () {

    int n;

    printf ("Ingrese un valor: ");
    scanf("%d", &n);
    while (n<=0) {
        printf ("El valor ingresado tiene que ser positivo, intentelo nuevamente: ");
        scanf ("%d", &n);
    }

    return n;

}

int main () {

    int n = pedir_entero ();
    int p = nesimo_primo (n);
    printf ("El primo numero %d es: %d\n", n, p);

    return 0;
    
}